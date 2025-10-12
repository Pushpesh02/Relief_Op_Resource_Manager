#include <stdio.h>
#include <string.h>
#include "truck.h"

void initTruckStack(TruckStack* s) {
    s->top = -1;
}

int pushTruck(TruckStack* s, int id, char item[], int qty) {
    if (s->top == STACK_MAX - 1) return 0;
    s->top++;
    s->data[s->top].id = id;
    strcpy(s->data[s->top].item, item);
    s->data[s->top].qty = qty;
    return 1;
}

int popTruck(TruckStack* s, TruckLoad* out) {
    if (s->top == -1) return 0;
    if (out) {
        out->id = s->data[s->top].id;
        strcpy(out->item, s->data[s->top].item);
        out->qty = s->data[s->top].qty;
    }
    s->top--;
    return 1;
}

void displayTrucks(TruckStack* s) {
    printf("\n--- Loaded Trucks (Top first) ---\n");
    if (s->top == -1) {
        printf("  (none)\n");
        return;
    }
    int i;
    for (i = s->top; i >= 0; i--) {
        printf("  Truck %d : %s x %d\n", s->data[i].id, s->data[i].item, s->data[i].qty);
    }
}
