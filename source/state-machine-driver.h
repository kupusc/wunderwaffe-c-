#pragma once

typedef int (state_machine_driver_handler_t)();

void state_machine_driver_install_handler(int state, int interrogation, state_machine_driver_handler_t handler);
int state_machine_driver_handle(int interrogation);
void state_machine_driver_init();