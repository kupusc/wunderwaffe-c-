#include "multitask.h"
#include <boost/thread.hpp>
#include <boost/lockfree/queue.hpp>
#include <cstdlib>

int execute(const char* command)
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

namespace
{
    using task_t = std::function<void()>;
    task_t func = [](){};

    boost::lockfree::queue<task_t*> q{1000};
    void producer()
    {
        q.push(&func);
    }
}
