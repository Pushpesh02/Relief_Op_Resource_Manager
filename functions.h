#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h" 

void add_resource(SystemState *state);
void view_resources(SystemState *state);


void push_to_truck(SystemState *state);
void pop_from_truck(SystemState *state);


void enqueue_victim(SystemState *state);
void dequeue_victim(SystemState *state); 

// --- Reporting (Later) ---

#endif
