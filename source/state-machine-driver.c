#include "state-machine-driver.h"

void state_machine_driver_install_handler(int state,
        int interrogation,
        state_machine_driver_handler_t *handler,
        struct state_machine_data *data)
{
    data->handlers[state*interrogation] = handler;
}

int state_machine_driver_handle(int interrogation,
                                struct state_machine_data *data)
{
    state_machine_driver_handler_t *func = data->handlers[data->current_state * interrogation];
    data->current_state = (*func)();
    return data->current_state;
}

void state_machine_driver_init(struct state_machine_data *data)
{
    data->current_state = 0;
}