#include <CppUTest/TestHarness.h>

extern "C"
{
    #include <state-machine-driver.h>
}

TEST_GROUP(state_machine_driver_must)
{
    void setup()
    {
        state_machine_driver_init();
    }
};

TEST(state_machine_driver_must, link)
{
    state_machine_driver_install_handler(0,0,0);
}

int test_handler0()
{
    return 5;
}

int test_handler1()
{
    return 2;
}

TEST(state_machine_driver_must, handle_interrogation_in_initial_state_and_return_the_next_state_returned_by_handler)
{
    const int state = 0;
    const int interrogation = 2;
    state_machine_driver_install_handler(state, interrogation, test_handler0);
    CHECK_EQUAL(test_handler0(), state_machine_driver_handle(interrogation));
}

TEST(state_machine_driver_must, keep_internal_state)
{
    const int initial_state = 0;
    const int interrogation0 = 0;
    const int interrogation1 = 1;
    const int state0 = test_handler0();
    const int state1 = test_handler1();
    
    state_machine_driver_install_handler(initial_state, interrogation0, test_handler0);
    state_machine_driver_install_handler(state0, interrogation1, test_handler1);

    CHECK_EQUAL(state0, state_machine_driver_handle(interrogation0));
    CHECK_EQUAL(state1, state_machine_driver_handle(interrogation1));
}

TEST(state_machine_driver_must, be_immune_to_race_conditions)
{
    
}