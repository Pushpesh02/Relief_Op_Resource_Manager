#include <stdio.h>
#include <string.h>
#include "admin.h"
#include "user.h"
#include "resource.h"
#include "victim.h"
#include "truck.h"

/* simple admin login (username/password) */
int adminLogin() {
    char u[50], p[50];
    printf("Username: "); scanf("%49s", u);
    printf("Password: "); scanf("%49s", p);
    if (strcmp(u, "admin") == 0 && strcmp(p, "1234") == 0) { printf("Login success.\n"); return 1; }
    printf("Invalid admin credentials.\n"); return 0;
}

void authMenu(Resource** pres, VictimQueues* pvq, TruckStack* ptrucks) {
    int ch = 0;
    while (1) {
        printf("\nLogin as:\n1. Admin\n2. User\n3. Save All & Exit\n4. Exit without Save\nChoice: ");
        if (scanf("%d", &ch) != 1) { while (getchar()!='\n'); ch = 0; }
        if (ch == 1) {
            if (adminLogin()) {
                *pres = adminMenu(*pres, pvq, ptrucks);
            }
        } else if (ch == 2) {
            *pres = userMenu(*pres, pvq);
        } else if (ch == 3) {
            saveResources(*pres, "resources.txt");
            saveVictims(pvq, "victims.txt");
            saveTrucks(ptrucks, "trucks.txt");
            printf("Saved all. Exiting.\n");
            break;
        } else if (ch == 4) {
            printf("Exiting without save.\n"); break;
        } else {
            printf("Invalid choice.\n");
        }
    }
}
