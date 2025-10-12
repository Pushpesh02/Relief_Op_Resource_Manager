#ifndef VICTIM_H
#define VICTIM_H

typedef struct Victim {
    int id;
    char name[50];
    int age;
    struct Victim* next;
} Victim;

/* Basic FIFO queue with front/rear. */
typedef struct {
    Victim* front;
    Victim* rear;
} Queue;

/* Two-queue priority model: children/seniors first, then adults. */
typedef struct {
    Queue priorityQ;  /* age <= 12 or age >= 60 */
    Queue normalQ;    /* everyone else */
    int next_id;      /* to assign unique IDs */
} VictimQueues;

/* Queue helpers */
void initQueue(Queue* q);
int isEmpty(Queue* q);
void enqueue(Queue* q, Victim* v);
Victim* dequeue(Queue* q);

/* Victim system (priority wrapper) */

void initVictimQueues(VictimQueues* vq);
int registerVictim(VictimQueues* vq, char name[], int age);
Victim* serveNextVictim(VictimQueues* vq);
void displayVictims(VictimQueues* vq);
void freeVictimQueues(VictimQueues* vq);

/* TODO (Phase-2): int saveVictims(VictimQueues* vq, char path[]);
   TODO (Phase-2): int loadVictims(VictimQueues* vq, char path[]); */

#endif
