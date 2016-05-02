#include <CppUTest/TestHarness.h>
#include <multitask.h>
// #include <memory>

//////////  Stubs /////////

//////// Fixture //////////

TEST_GROUP(multitask)
{
    void setup()
    {
    }
};


//////// Tests /////////////

TEST(multitask, does_nothing)
{
    worker w;
    auto t = create_task("echo task");
    auto t2 = create_task(std::function<void()>([](){}));
    w.accept(t.get());
    w.accept(t2.get());
    w.start();
    w.join_all();
}
