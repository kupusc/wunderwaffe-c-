#pragma once

typedef int (state_machine_driver_handler_t)();
struct state_machine_object;

void state_machine_driver_install_handler(int state,
        int interrogation,
        state_machine_driver_handler_t handler,
        struct state_machine_object const *);

int state_machine_driver_handle(int interrogation,
                                struct state_machine_object const *);

void state_machine_driver_init(struct state_machine_object const *);