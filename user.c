#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "user.h"

Resource* userMenu(Resource* resHead, VictimQueues* vq) {
    int ch = 0;
    while (1) {
        printf("\n--- USER MENU ---\n");
        printf("1. Register as Victim\n");
        printf("2. Display Victims\n");
        printf("3. Serve Next Victim\n");
        printf("4. Back\n");
        printf("Choice: ");
        if (scanf("%d", &ch) != 1) { while (getchar()!='\n'); 
            ch = 0; }

        if (ch == 1) {
            char name[50]; int age;
            printf("Name: "); scanf("%49s", name);
            printf("Age: "); scanf("%d", &age);
            registerVictim(vq, name, age);
        } else if (ch == 2) {
            displayVictims(vq);
        } else if (ch == 3) {
            Victim* v = serveNextVictim(vq);
            if (!v) {
                printf("No victims waiting.\n");
            } else {
                char res[50]; int qty;
                printf("Serving %s (ID:%d, Age:%d)\n", v->name, v->id, v->age);
                printf("Enter resource: "); scanf("%49s", res);
                printf("Quantity: "); scanf("%d", &qty);
                Resource* found = findResource(resHead, res);
                if (!found || found->quantity < qty) {
                    printf("Insufficient stock.\n");
                    registerVictim(vq, v->name, v->age);
                } else {
                    resHead = removeResource(resHead, res, qty);
                    printf("Allocated %s x %d to %s\n", res, qty, v->name);
                }
                free(v);
            }
        } else if (ch == 4) {
            printf("Returning to login menu.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return resHead;
}
