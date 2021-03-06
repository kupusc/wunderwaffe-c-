#include <CppUTest/TestHarness.h>

extern "C"
{
#include <state-machine-driver.h>
}


//////////  Stubs /////////

int test_handler0()
{
    return 5;
}

int test_handler1()
{
    return 2;
}


//////// Fixture //////////

TEST_GROUP(state_machine_driver_must)
{
    state_machine_driver_handler_t *handlers[8];
    state_machine_driver driver;
    void setup()
    {
        driver.configuration.handlers = handlers;
        state_machine_driver_init(&driver);
    }
};


//////// Tests /////////////

TEST(state_machine_driver_must, link)
{
    state_machine_driver_install_handler(0, 0, 0, &driver);
}


TEST(state_machine_driver_must, handle_interrogation_in_initial_state_and_return_the_next_state_returned_by_handler)
{
    const int state = driver.current_state;
    const int interrogation = 2;
    state_machine_driver_install_handler(state, interrogation, test_handler0, &driver);
    CHECK_EQUAL(test_handler0(), state_machine_driver_handle(interrogation, &driver));
}

TEST(state_machine_driver_must, keep_internal_state)
{
    const int initial_state = driver.current_state;
    const int interrogation0 = 0;
    const int interrogation1 = 1;
    const int state0 = test_handler0();
    const int state1 = test_handler1();

    state_machine_driver_install_handler(initial_state, interrogation0, test_handler0, &driver);
    state_machine_driver_install_handler(state0, interrogation1, test_handler1, &driver);

    CHECK_EQUAL(state0, state_machine_driver_handle(interrogation0, &driver));
    CHECK_EQUAL(state1, state_machine_driver_handle(interrogation1, &driver));
}
