#include "state-machine.h"

handler_t* handlers[100][100];

int current_state = 0;

void install_handler(int state, int interrogation, handler_t* handler)
{
    handlers[state][interrogation] = handler;
}

void handle(int interrogation)
{
    handler_t* func = handlers[current_state][interrogation];
    current_state = (*func)();
}
