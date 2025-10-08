
// Struct for a single resource item
typedef struct Resource {
    char name[50];
    int quantity;
    struct Resource *next; // For the Linked List
} Resource;

// Struct for a single victim
typedef struct Victim {
    char name[50];
    int age;
    char category[10]; // "child", "adult", "senior"
    struct Victim *next; // For the Queue
} Victim;
