#ifndef TRUCK_H
#define TRUCK_H

#define STACK_MAX 50

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
int saveTrucks(TruckStack* s, char path[]);
int loadTrucks(TruckStack* s, char path[]);

#endif
