#include "state-machine-driver.h"

state_machine_driver_handler_t* handlers[100][100];

int current_state = 0;

void state_machine_driver_install_handler(int state, int interrogation, state_machine_driver_handler_t* handler)
{
    handlers[state][interrogation] = handler;
}

int state_machine_driver_handle(int interrogation)
{
    state_machine_driver_handler_t* func = handlers[current_state][interrogation];
    current_state = (*func)();
    return current_state;
}

void state_machine_driver_init()
{
    current_state = 0;
}