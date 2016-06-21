#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

struct state_machine_driver;

void state_machine_start_synchronously(struct state_machine_driver*);
void state_machine_start_asynchronously(struct state_machine_driver*);
void state_machine_stop(struct state_machine_driver*);

#endif
