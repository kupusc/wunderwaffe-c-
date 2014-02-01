#pragma once

typedef int (handler_t)();

void install_handler(int state, int interrogation, handler_t handler);
int handle(int interrogation);
void init();