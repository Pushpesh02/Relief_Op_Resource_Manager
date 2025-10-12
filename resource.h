#ifndef RESOURCE_H
#define RESOURCE_H

typedef struct Resource {
    char name[50];
    int quantity;
    struct Resource* next;
} Resource;


Resource* addResource(Resource* head, char name[], int qty);


Resource* removeResource(Resource* head, char name[], int qty);


Resource* findResource(Resource* head, char name[]);


void displayResources(Resource* head);

void freeResources(Resource* head);


#endif
