#pragma once

typedef int (handler_t)();

void install_handler(int state, int interrogation, handler_t handler);
void handle(int interrogation);