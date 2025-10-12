#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "victim.h"

/* Queue basics */
void initQueue(Queue* q) { q->front = NULL; q->rear = NULL; }
int isEmpty(Queue* q) { return q->front == NULL; }

void enqueue(Queue* q, Victim* v) {
    v->next = NULL;
    if (q->rear == NULL) {
        q->front = v;
        q->rear = v;
    } else {
        q->rear->next = v;
        q->rear = v;
    }
}

Victim* dequeue(Queue* q) {
    if (q->front == NULL) return NULL;
    Victim* v = q->front;
    q->front = v->next;
    if (q->front == NULL) q->rear = NULL;
    v->next = NULL;
    return v;
}

/* Victim system (two queues) */
void initVictimQueues(VictimQueues* vq) {
    initQueue(&vq->priorityQ);
    initQueue(&vq->normalQ);
    vq->next_id = 1;
}

int registerVictim(VictimQueues* vq, char name[], int age) {
    Victim* v = (Victim*)malloc(sizeof(Victim));
    if (!v) return 0;
    v->id = vq->next_id++;
    strcpy(v->name, name);
    v->age = age;
    v->next = NULL;

    if (age <= 12 || age >= 60) enqueue(&vq->priorityQ, v);
    else enqueue(&vq->normalQ, v);
    return 1;
}

Victim* serveNextVictim(VictimQueues* vq) {
    Victim* v = dequeue(&vq->priorityQ);
    if (v) return v;
    return dequeue(&vq->normalQ);
}

void printQueue(Queue* q, char title[]) {
    printf("%s\n", title);
    if (q->front == NULL) {
        printf("  (none)\n");
        return;
    }
    Victim* cur = q->front;
    while (cur) {
        printf("  ID:%d Name:%s Age:%d\n", cur->id, cur->name, cur->age);
        cur = cur->next;
    }
}

void displayVictims(VictimQueues* vq) {
    printf("\n--- Waiting Victims ---\n");
    printQueue(&vq->priorityQ, "Priority (children & seniors):");
    printQueue(&vq->normalQ,   "Normal (adults):");
}

void freeQueue(Queue* q) {
    Victim* cur = q->front;
    while (cur) {
        Victim* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
    q->front = q->rear = NULL;
}

void freeVictimQueues(VictimQueues* vq) {
    freeQueue(&vq->priorityQ);
    freeQueue(&vq->normalQ);
}
