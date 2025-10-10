#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

void enqueue_victim(SystemState *state) {
    Victim *new_victim = (Victim *)malloc(sizeof(Victim));
    if (new_victim == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter victim's name: ");
    scanf("%s", new_victim->name);
    printf("Enter age: ");
    scanf("%d", &new_victim->age);


    if (new_victim->age < 12) {
        strcpy(new_victim->category, "child");
    } else if (new_victim->age >= 60) {
        strcpy(new_victim->category, "senior");
    } else {
        strcpy(new_victim->category, "adult");
    }
    
    new_victim->next = NULL;

    // Priority queue : children/seniors go to the front
    if (state->queue_head == NULL) {
        state->queue_head = new_victim;
        state->queue_tail = new_victim;
    } else if (strcmp(new_victim->category, "child") == 0 || strcmp(new_victim->category, "senior") == 0) {
        new_victim->next = state->queue_head;
        state->queue_head = new_victim;
    } else {
        state->queue_tail->next = new_victim;
        state->queue_tail = new_victim;
    }

    printf("Victim '%s' added to the queue as a %s.\n", new_victim->name, new_victim->category);
}

void dequeue_victim(SystemState *state) {
    printf("Function to serve victim (Dequeue) is pending implementation.\n");
}
