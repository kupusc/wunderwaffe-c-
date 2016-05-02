#include "multitask.h"
#include <boost/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include <cstdlib>

int execute_shell(const char* command)
{
    FILE * f = popen( command, "r" );
    if ( f == 0 ) {
        fprintf( stderr, "Could not execute\n" );
        return -1;
    }
    const int BUFSIZE = 1000;
    char buf[ BUFSIZE ];
    while( fgets( buf, BUFSIZE,  f ) ) {
        fprintf( stdout, "%s", buf  );
    }
    pclose( f );
    return 0;
}

int execute(const char* command)
{
    return execute_shell(command);
}

template<>
void task<const char*>::operator()()
{
    execute_shell(substance);
}

template<>
void task<std::function<void()> >::operator()()
{
    substance();
}

template <typename T>
std::unique_ptr<itask> create_task(T t)
{
    return std::unique_ptr<itask>(new task<T>(t));
}

template std::unique_ptr<itask> create_task(const char*);
template std::unique_ptr<itask> create_task(std::function<void()>);

template <typename T>
task<T>::task(T t)
: substance(t)
{}

struct task_queue
{
    task_queue()
    : q{1000}
    {}

    void push(itask* t)
    {
        q.push(t);
    }

    bool pop()
    {
        itask* t;
        const bool had_something = q.pop(t);
        if(had_something)
        {
            (*t)();
        }
        return had_something;
    }

private:
    boost::lockfree::queue<itask*> q;
};

struct worker::impl
{
    boost::thread_group threads;
    task_queue tq;
};

worker::worker()
: d(new impl)
{}

void worker::accept(itask* t)
{
    d->tq.push(t);
}

void worker::start()
{
    for(unsigned i = 0; i < 4; ++i) {
        d->threads.add_thread(new boost::thread([&](){d->tq.pop();}));
    }
}

worker::~worker()
{
    d->threads.join_all();
    delete d;
}
