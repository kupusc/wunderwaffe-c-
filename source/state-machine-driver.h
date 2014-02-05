#pragma once

typedef int (state_machine_driver_handler_t)();

struct state_machine_data
{
    state_machine_driver_handler_t **handlers;
    int current_state;
};

void state_machine_driver_install_handler(int state,
        int interrogation,
        state_machine_driver_handler_t handler,
        struct state_machine_data *);

int state_machine_driver_handle(int interrogation,
                                struct state_machine_data *);

void state_machine_driver_init(struct state_machine_data *);