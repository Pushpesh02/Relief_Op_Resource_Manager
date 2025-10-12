#include <stdio.h>
#include "auth.h"
#include "resource.h"
#include "victim.h"
#include "truck.h"

int main() {
    Resource* resources = NULL;
    VictimQueues victims;
    TruckStack trucks;

    initVictimQueues(&victims);
    initTruckStack(&trucks);

    printf("=== Relief Op Resource Management System ===\n");
    authMenu(&resources, &victims, &trucks);

    freeResources(resources);
    freeVictimQueues(&victims);
    return 0;
}
