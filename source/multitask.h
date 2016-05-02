#pragma once

#include <functional>
#include <memory>

int execute(const char* command);
int execute_shell(const char* command);

struct itask
{
    virtual void operator()() = 0;
    virtual ~itask(){}
};

template <typename T>
struct task: public itask
{
    task(T t);
    void operator()();

private:
    T substance;
};

template<>
void task<const char*>::operator()();

template<>
void task<std::function<void()> >::operator()();

struct iworker
{
    virtual void accept(itask*) = 0;
    virtual void start() = 0;
    virtual ~iworker(){}
};

struct worker: public iworker
{
    worker();
    void accept(itask* t);
    void start();
    ~worker();

private:
    struct impl;
    impl *d;
};

template <typename T>
std::unique_ptr<itask> create_task(T t);
