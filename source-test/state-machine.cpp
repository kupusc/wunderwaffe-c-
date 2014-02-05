#include <CppUTest/TestHarness.h>

extern "C"
{
#include <state-machine-driver.h>
}


//////////  Stubs /////////


//////// Fixture //////////

TEST_GROUP(state_machine_must)
{
    void setup()
    {
    }
};


//////// Tests /////////////

TEST(state_machine_must, link)
{
    FAIL("me");
}
