#include <CppUTest/TestHarness.h>

extern "C"
{
#include <state-machine.h>
#include "state-machine-driver.h"
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

TEST(state_machine_must, start_synchronously)
{
    state_machine_driver my_state_machine_data;
    state_machine_start_synchronously(&my_state_machine_data);
}
