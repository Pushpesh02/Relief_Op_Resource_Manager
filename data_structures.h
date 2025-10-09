#ifndef STRUCTS_H
#define STRUCTS_H

#define MAX_TRUCK_CAPACITY 10


typedef struct Resource {
    char name[50];
    int quantity;
    struct Resource *next; 
} Resource;

typedef struct Victim {
    char name[50];
    int age;
    char category[10]; 
    struct Victim *next; 
} Victim;

typedef struct {
    char item_name[50];
    int quantity;
} Supply;

typedef struct {
    Resource *resource_head;
    Victim *queue_head;
    Victim *queue_tail;
    Supply truck_stack[MAX_TRUCK_CAPACITY];
    int stack_top;
} SystemState;


#endif 
