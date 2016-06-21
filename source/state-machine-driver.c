#include "state-machine-driver.h"

void state_machine_driver_install_handler(int state,
        int interrogation,
        state_machine_driver_handler_t *handler,
        struct state_machine_driver *driver)
{
    driver->configuration.handlers[state*interrogation] = handler;
}

int state_machine_driver_handle(int interrogation,
                                struct state_machine_driver *driver)
{
    state_machine_driver_handler_t *func = driver->configuration.handlers[driver->current_state * interrogation];
    driver->current_state = (*func)();
    return driver->current_state;
}

void state_machine_driver_init(struct state_machine_driver *data)
{
    data->current_state = 0;
}
