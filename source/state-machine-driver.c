#include "state-machine-driver.h"

state_machine_driver_handler_t *handlers[100][100];

int current_state = 0;

void state_machine_driver_install_handler(int state,
        int interrogation,
        state_machine_driver_handler_t *handler,
        struct state_machine_object const *object)
{
    handlers[state][interrogation] = handler;
}

int state_machine_driver_handle(int interrogation,
                                struct state_machine_object const *object)
{
    state_machine_driver_handler_t *func = handlers[current_state][interrogation];
    current_state = (*func)();
    return current_state;
}

void state_machine_driver_init(struct state_machine_object const *object)
{
    current_state = 0;
}