#include <stdio.h>
#include "resource.h"
#include "victim.h"
#include "truck.h"

void authMenu(Resource** pres, VictimQueues* pvq, TruckStack* ptrucks);
int loadResources(char path[]);
int main() {
    Resource* resources = NULL;
    VictimQueues vq;
    TruckStack trucks;

    initVictimQueues(&vq);
    initTruckStack(&trucks);

    resources = loadResources("resources.txt");
    loadVictims(&vq, "victims.txt");
    loadTrucks(&trucks, "trucks.txt");

    printf("=== Disaster Relief Resource Management System (Phase-2) ===\n");
    authMenu(&resources, &vq, &trucks);


    freeResources(resources);
    freeVictimQueues(&vq);

    return 0;
}
