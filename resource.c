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

// Placeholder functions for Stack (Truck Dispatch)
void push_to_truck(SystemState *state) {
    printf("Function to load truck (Stack) is pending implementation.\n");
}

void pop_from_truck(SystemState *state) {
    printf("Function to dispatch truck (Stack) is pending implementation.\n");
