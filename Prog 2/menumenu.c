#include <stdio.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

#define MAX 10

typedef char String[20];

typedef struct{
    float price;
    int quantity;
    String name;
} dish;

typedef struct{
    dish entree[3];
    dish sides[3];
    dish desserts[3];
} menu;

void getMethod(int *userInput) {
    printf("--FOOD MENU--\n");
    printf("1. Add order\n");
    printf("2. Remove Order\n");
    printf("3. Display Entree\n");
    printf("4. Display Sides\n");
    printf("5. Display Desserts\n");
    printf("6. Total Purchase\n");
    printf("7. Exit\n\n");

    printf("Enter option: ");
    scanf("%d", userInput);
}

dish createDish(float price, String name, int quantity);
menu loadMenu();
void displayEntree(menu main_menu, int size);
void displaySides(menu main_menu, int size);
void displayDesserts(menu main_menu, int size);
void addOrder(dish *order_dish, int *total, dish all_orders[]);
void displayOrder(dish all_orders[], int total);
float sumAll(dish all_orders[], int total);
void removeDish(dish all_orders[], int *total, int index, int input, menu *main_menu);

int main(void) {
    int userInput;

    do {
        getMethod(&userInput);
        switch (userInput) {
            case 1:
                break;
            case 2:
                break;
            case 3:
                break;
            case 4:
                break;
            case 5:
                break;
            case 6:
                printf("\nExiting program...");
                break;
            default:
                break;
        }
    } while (userInput != 6)

    return 0;
}