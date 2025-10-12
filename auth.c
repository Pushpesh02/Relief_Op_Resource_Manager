#include <stdio.h>
#include <string.h>
#include "auth.h"
#include "admin.h"
#include "user.h"

int adminLogin() {
    char u[50], p[50];
    printf("Username: "); scanf("%49s", u);
    printf("Password: "); scanf("%49s", p);
    if (strcmp(u, "admin") == 0 && strcmp(p, "1234") == 0) {
        printf("Login success.\n");
        return 1;
    }
    printf("Invalid credentials.\n");
    return 0;
}

void authMenu(Resource** res, VictimQueues* vq, TruckStack* trucks) {
    int ch = 0;
    while (1) {
        printf("\nLogin as:\n1. Admin\n2. User\n3. Exit\nChoice: ");
        if (scanf("%d", &ch) != 1) { while (getchar()!='\n'); 
            ch = 0; }

        if (ch == 1) {
            if (adminLogin()) {
                *res = adminMenu(*res, vq, trucks);
            }
        } else if (ch == 2) {
            *res = userMenu(*res, vq);
        } else if (ch == 3) {
            printf("Goodbye.\n");
            break;
        } else {
            printf("Invalid choice.\n");
        }
    }
}
