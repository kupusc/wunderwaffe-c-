#include "state-machine-driver.h"

void state_machine_driver_install_handler(int state,
        int interrogation,
        state_machine_driver_handler_t *handler,
        struct state_machine_object *object)
{
    object->handlers[state*interrogation] = handler;
}

int state_machine_driver_handle(int interrogation,
                                struct state_machine_object *object)
{
    state_machine_driver_handler_t *func = object->handlers[object->current_state * interrogation];
    object->current_state = (*func)();
    return object->current_state;
}

void state_machine_driver_init(struct state_machine_object *object)
{
    object->current_state = 0;
}