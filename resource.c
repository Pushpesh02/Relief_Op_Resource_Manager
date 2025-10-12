#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "resource.h"

Resource* makeNode(char name[], int qty) {
    Resource* r = (Resource*)malloc(sizeof(Resource));
    if (!r) return NULL;
    strcpy(r->name, name);
    r->quantity = qty;
    r->next = NULL;
    return r;
}

Resource* findResource(Resource* head, char name[]) {
    Resource* cur = head;
    while (cur) {
        if (strcmp(cur->name, name) == 0) return cur;
        cur = cur->next;
    }
    return NULL;
}

Resource* addResource(Resource* head, char name[], int qty) {
    if (qty <= 0) return head;
    Resource* found = findResource(head, name);
    if (found) {
        found->quantity += qty;
        return head;
    }
    /* insert at head for simplicity */
    Resource* node = makeNode(name, qty);
    if (!node) {
        printf("Memory error adding resource.\n");
        return head;
    }
    node->next = head;
    return node;
}

Resource* removeResource(Resource* head, char name[], int qty) {
    if (qty <= 0) return head;
    Resource* cur = head;
    Resource* prev = NULL;
    while (cur) {
        if (strcmp(cur->name, name) == 0) break;
        prev = cur;
        cur = cur->next;
    }
    if (!cur) {
        printf("Resource '%s' not found.\n", name);
        return head;
    }
    if (cur->quantity > qty) {
        cur->quantity -= qty;
        return head;
    }
    /* remove node */
    if (prev) prev->next = cur->next;
    else head = cur->next;
    free(cur);
    return head;
}

void displayResources(Resource* head) {
    printf("\n--- Resource Stock ---\n");
    if (!head) {
        printf("  (none)\n");
        return;
    }
    Resource* cur = head;
    while (cur) {
        printf("  %s : %d\n", cur->name, cur->quantity);
        cur = cur->next;
    }
}

void freeResources(Resource* head) {
    Resource* cur = head;
    while (cur) {
        Resource* tmp = cur;
        cur = cur->next;
        free(tmp);
    }
}
