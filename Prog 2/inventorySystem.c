#include <stdio.h>
#define MAX 20

typedef struct {
	int id;
	char name[20];
	float price;
	int quantity;
	char supplier[20];
} Item;

void getMethod(int *choice) {
	printf("Inventory management system\n");
	printf("1. Add item\n");
	printf("2. Search item by ID\n");
	printf("3. Display inventory\n");
	printf("4. Generate report\n");
	printf("5. Exit\n");

	printf("Enter option: ");
	scanf("%d", choice);
}

void addItem(int itemNo, float *sales, int *totalItems, Item inventory[]) {
	int temp;
	int status = 1;

	do {
		printf("Enter item ID: ");
		scanf("%d", &temp);

		if (temp <= 0) {
			printf("Invalid ID\n");
		} else {
			for (int i = 0; i <= itemNo; i++) {
				if (inventory[i].id == temp) {
					printf("ID already exists\n");
					break;
				}
			}
			inventory[itemNo].id = temp;
			status = 0;
		}
	} while (status);

	printf("Enter item name: ");
	scanf("%s", inventory[itemNo].name);

	printf("Enter item price: ");
	scanf("%f", &inventory[itemNo].price);

	printf("Enter item quantity: ");
	scanf("%d", &inventory[itemNo].quantity);

	*totalItems += inventory[itemNo].quantity;
	*sales += inventory[itemNo].price * inventory[itemNo].quantity;

	printf("Enter item supplier: ");
	scanf("%s", inventory[itemNo].supplier);

	printf("Item added to inventory.\n\n");
}

void searchItem(int id, int itemNo, Item inventory[]) {
	for (int i = 0; i < itemNo; i++) {
		if (inventory[i].id == id) {
			printf("ID: %d\n", inventory[i].id);
			printf("Name: %s\n", inventory[i].name);
			printf("Price: %.2f\n", inventory[i].price);
			printf("Quantity: %d\n", inventory[i].quantity);
			printf("Supplier: %s\n\n", inventory[i].supplier);
			return;
		}
	}
	printf("Item not found.\n\n");
}

void displayInventory(int itemNo, Item inventory[]) {
	if (!itemNo) {
		printf("No items in inventory.\n\n");
		return;
	}

	for (int i = 0; i < itemNo; i++) {
		printf("ID: %d\n", inventory[i].id);
		printf("Name: %s\n", inventory[i].name);
		printf("Price: %.2f\n", inventory[i].price);
		printf("Quantity: %d\n", inventory[i].quantity);
		printf("Supplier: %s\n\n", inventory[i].supplier);
	}
}

void generateReport(int itemNo, float sales, int totalItems) {
	if (!itemNo) {
		printf("No items in inventory.\n\n");
		return;
	}

	printf("Total sales: $%.2f\n", sales);
	printf("Total items: %d\n\n", totalItems);
}

int main(void) {
	int choice;
	int id;

	int itemNo = 0;
	int totalItems = 0;
	float sales = 0;

	Item inventory[MAX];

	do {
		getMethod(&choice);
		switch (choice) {
			case 1:
				addItem(itemNo, &sales, &totalItems, inventory);
				itemNo++;
				break;
			case 2:
				printf("Enter item ID: ");
				scanf("%d", &id);
				searchItem(id, itemNo, inventory);
				break;
			case 3:
				displayInventory(itemNo, inventory);
				break;
			case 4:
				generateReport(itemNo, sales, totalItems);
				break;
			case 5:
				break;
			default:
				printf("Invalid option\n\n");
		}
	} while (choice != 5);

	printf("Exiting program.");

	return 0;
}
