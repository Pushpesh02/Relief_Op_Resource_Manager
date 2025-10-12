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


#endif 
