#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

// --- Linked List Functions ---

void add_resource(SystemState *state) {
    Resource *new_resource = (Resource *)malloc(sizeof(Resource));
    if (new_resource == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter resource name: ");
    scanf("%s", new_resource->name);
    printf("Enter quantity: ");
    scanf("%d", &new_resource->quantity);

    new_resource->next = NULL;

    if (state->resource_head == NULL) {
        state->resource_head = new_resource;
    } else {
        Resource *current = state->resource_head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_resource;
    }
    printf("Resource added successfully!\n");
}

void view_resources(SystemState *state) {
    if (state->resource_head == NULL) {
        printf("No resources available.\n");
        return;
    }
    printf("\n--- Available Resources ---\n");
    Resource *current = state->resource_head;
    while (current != NULL) {
        printf("Name: %s, Quantity: %d\n", current->name, current->quantity);
        current = current->next;
    }
    printf("---------------------------\n");
}

void push_to_truck(SystemState *state) {
    if (state->stack_top >= MAX_TRUCK_CAPACITY - 1) {
        printf("Truck is full. Cannot load more supplies.\n");
        return;
    }

    char item_name[50];
    int quantity;

    printf("Enter item name to load: ");
    scanf("%s", item_name);
    printf("Enter quantity: ");
    scanf("%d", &quantity);

    // Find the resource in the linked list and check if there's enough
    Resource *current = state->resource_head;
    while(current != NULL) {
        if (strcmp(current->name, item_name) == 0 && current->quantity >= quantity) {
            current->quantity -= quantity;
            state->stack_top++;
            strcpy(state->truck_stack[state->stack_top].item_name, item_name);
            state->truck_stack[state->stack_top].quantity = quantity;
            printf("Loaded %d units of %s onto the truck.\n", quantity, item_name);
            return;
        }
        current = current->next;
    }
    printf("Resource not found or insufficient quantity.\n");
}

void pop_from_truck(SystemState *state) {
    if (state->stack_top == -1) {
        printf("Truck is empty. Nothing to dispatch.\n");
        return;
    }
    
    Supply dispatched_item = state->truck_stack[state->stack_top];
    state->stack_top--;
    printf("Dispatched %d units of %s.\n", dispatched_item.quantity, dispatched_item.item_name);
}
