#ifndef STATE_MACHINE_DRIVER_H
#define STATE_MACHINE_DRIVER_H

typedef int (state_machine_driver_handler_t)();

struct state_machine_configuration
{
    state_machine_driver_handler_t **handlers;
};

struct state_machine_driver
{
    struct state_machine_configuration configuration;
    int current_state;
};

void state_machine_driver_install_handler(int state,
        int interrogation,
        state_machine_driver_handler_t handler,
        struct state_machine_driver *);

int state_machine_driver_handle(int interrogation,
                                struct state_machine_driver *);

void state_machine_driver_init(struct state_machine_driver *);

#endif
