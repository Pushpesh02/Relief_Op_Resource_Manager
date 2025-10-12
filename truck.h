#ifndef TRUCK_H
#define TRUCK_H

#define STACK_MAX 20

typedef struct {
    int id;
    char item[50];
    int qty;
} TruckLoad;

typedef struct {
    TruckLoad data[STACK_MAX];
    int top; 
} TruckStack;

void initTruckStack(TruckStack* s);
int pushTruck(TruckStack* s, int id, char item[], int qty); 
int popTruck(TruckStack* s, TruckLoad* out);
void displayTrucks(TruckStack* s);



#endif
