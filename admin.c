#include <stdio.h>
#include <string.h>
#include "admin.h"

Resource* adminMenu(Resource* resHead, VictimQueues* vqs, TruckStack* trucks) {
    int ch = 0;
    while (1) {
        printf("\n--- ADMIN MENU ---\n");
        printf("1. Add Resource\n");
        printf("2. Remove Resource\n");
        printf("3. Display Resources\n");
        printf("4. Load Truck\n");
        printf("5. Dispatch Truck\n");
        printf("6. Display Trucks\n");
        printf("7. View Victims\n");
        printf("8. Logout\n");
        printf("Choice: ");
        if (scanf("%d", &ch) != 1) { while (getchar()!='\n'); 
            ch = 0; }

        if (ch == 1) {
            char name[50]; int qty;
            printf("Resource name: "); scanf("%49s", name);
            printf("Quantity: "); scanf("%d", &qty);
            resHead = addResource(resHead, name, qty);
        } else if (ch == 2) {
            char name[50]; int qty;
            printf("Resource name: "); scanf("%49s", name);
            printf("Quantity to remove: "); scanf("%d", &qty);
            resHead = removeResource(resHead, name, qty);
        } else if (ch == 3) {
            displayResources(resHead);
        } else if (ch == 4) {
            int id, qty; char item[50];
            printf("Truck ID: "); scanf("%d", &id);
            printf("Item to load: "); scanf("%49s", item);
            printf("Quantity: "); scanf("%d", &qty);
            Resource* found = findResource(resHead, item);
            if (!found || found->quantity < qty)
                printf("Not enough stock.\n");
            else {
                if (!pushTruck(trucks, id, item, qty))
                    printf("Truck stack full.\n");
                else {
                    resHead = removeResource(resHead, item, qty);
                    printf("Loaded and stock updated.\n");
                }
            }
        } else if (ch == 5) {
            TruckLoad t;
            if (popTruck(trucks, &t))
                printf("Dispatched Truck %d (%s x %d)\n", t.id, t.item, t.qty);
            else printf("No trucks to dispatch.\n");
        } else if (ch == 6) {
            displayTrucks(trucks);
        } else if (ch == 7) {
            displayVictims(vqs);
        } else if (ch == 8) {
            printf("Admin logout.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
    return resHead;
}
