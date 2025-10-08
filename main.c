#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Forward declarations for functions
void admin_menu();
void user_menu();
void login();

int main() {
    printf("Welcome to Disaster Relief Resource Management System\n");
    printf("--------------------------------------------------\n");
    login();
    return 0;
}

void login() {
    int choice;
    printf("Login as:\n");
    printf("1. Admin\n");
    printf("2. User\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    if (choice == 1) {
        char username[20], password[20];
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "1234") == 0) {
            printf("\nAdmin login successful!\n");
            admin_menu();
        } else {
            printf("\nInvalid credentials. Please try again.\n");
            login();
        }
    } else if (choice == 2) {
        printf("\nUser login successful!\n");
        user_menu();
    } else {
        printf("\nInvalid choice. Please try again.\n");
        login();
    }
}

// Empty functions for now, to be implemented later
void admin_menu() {}
void user_menu() {}
