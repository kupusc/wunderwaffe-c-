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
    auto t = create_task("echo jojo");
    w.accept(t.get());
    w.start();
    // FAIL("dupa");
}
