#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structs.h"


void add_resource(Resource **head);
void view_resources(Resource *head);

void push_to_truck(Resource **r_head, Supply truck[], int *top);
void pop_from_truck(Supply truck[], int *top);

void enqueue_victim(Victim **head, Victim **tail);
void dequeue_victim(Victim **head, Victim **tail);


void generate_report(Resource *r_head, Victim *v_head, Supply truck[], int top);

#endif 
