/* Instructions:
	The University of San Carlos has begun rolling out its newest locker technology: GraviLockers.
	These lockers are capable of fitting any amount of items, for as long as the total weight of all items
	does not exceed the weight limit of 5 KG. However, during shipping, the lockers' disk drives were damaged,
	and the firmware that made them work was lost. Luckily, the documentation for the structures remained intact.

	As students of DCISM, USC needs your help. Write the codes for the functions to make the lockers work again.
	Use the structures defined below.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXLOCKERS 10
#define WEIGHTLIMIT 5

typedef struct {
	char studID[9];
	char studName[65];
	char course[5];
} Student;

typedef struct {
	char itemName[33];
	float weight; /* Weight of the item to be stored */
} ItemDetails;

typedef struct ItemNode {
	ItemDetails item;
	struct ItemNode* nextItem;
} ItemNode, *ItemList;

typedef struct {
	Student owner;	 /* Details of the student who owns the locker */
	ItemList IL;	 /* Linked list representation of all the items inside a certain locker */
	int lockerStat;	 /* 0 if locker is Vacant, 1 if occupied */
	float totWeight; /* Total weight of all items in the locker */
} Locker;

/* Function depositItem(): This function will receive as parameter a Locker, a student ID, and an item to be
stored. The function will insert the item into the Locker's ItemList, which is sorted by weight. Heavier
items are stored at the end of the locker's ItemList. Before insertion, please make sure that the student ID
passed is the same as the student ID of the locker's owner. Also, make sure that the weight of all items,
including the new item to store, does not exceed the weight limit. */

void depositItem(Locker* L, char studID[], ItemDetails newItem) {
	if (strcmp(L->owner.studID, studID)) {
		printf("Accessing Wrong Locker!\n");
		return;
	}
	if (L->totWeight + newItem.weight > WEIGHTLIMIT) {
		printf("Weight Limit Exceeds. Locker full!\n");
		return;
	}

	L->totWeight += newItem.weight;

	ItemNode *new = malloc(sizeof(ItemNode));
	ItemNode *trav = L->IL;

	new->item = newItem;
	new->nextItem = NULL;

	int index = 0;

	while(trav != NULL) {
		if (trav->item.weight > newItem.weight && index == 0) {
			new->nextItem = trav;
			L->IL = new;
			return;
		}
		if (trav->item.weight < newItem.weight && trav->nextItem == NULL) {
			trav->nextItem = new;
			return;
		}
		if (trav->item.weight < newItem.weight && trav->nextItem->item.weight > newItem.weight) {
			new->nextItem = trav->nextItem;
			trav->nextItem = new;
			return;
		}

		trav = trav->nextItem;
		index++;
	}

	L->IL = new;
}

/* Function getHeavyItems(): This function will receive as parameter a Locker and a weight threshold/limit.
The function will go through all the items in the passed Locker's ItemList. If any item EXCEEDS the passed
threshold/limit, store that item into a new ItemList using insertFirst, and delete it from the locker's
ItemList. Return the ItemList of deleted items to the calling function. */

ItemList getHeavyItems(Locker *L, Locker *heavy, float limit) {
	ItemList heavyItems = malloc(sizeof(ItemNode));

	heavyItems = NULL;

	ItemNode *prev;
	ItemNode *trav = L->IL;
	ItemNode *temp;

	while(trav != NULL) {
		temp = heavyItems;

		if (trav->item.weight > limit) {
			heavy->totWeight += trav->item.weight;

			ItemNode *new = malloc(sizeof(ItemNode));

			new->item = trav->item;
			new->nextItem = NULL;

			prev->nextItem = trav->nextItem;
			free(trav);
			trav = prev->nextItem;

			if (heavyItems == NULL) {
				heavyItems = new;
			} else {
				new->nextItem = temp;
				heavyItems = new;
			}

			continue;
		}
		prev = trav;
		trav = trav->nextItem;
	}

	return heavyItems;
}

void displayItemList(Locker L) {
	ItemList trav;
	for (trav = L.IL; trav != NULL; trav = trav->nextItem) {
		printf("Item: %-15s | Weight: %-15.2f\n", trav->item.itemName, trav->item.weight);
	}
	printf("\nTotal Weight: %.2fkg\n\n", L.totWeight);
}

int main(void) {
	ItemDetails item1 = {"Prog 1 Book", 0.35};
	ItemDetails item2 = {"Shoes", 0.87};
	ItemDetails item3 = {"Laptop", 2.35};
	ItemDetails item4 = {"Keyboard", 1.17};

	Locker myLocker = {{"14101941", "Cris Militante", "BSCS"}, NULL, 1, 0};
	Locker heavyItems;

	heavyItems.IL = NULL;

	depositItem(&myLocker, "14101941", item4);
	depositItem(&myLocker, "14101941", item2);
	depositItem(&myLocker, "14101941", item3);
	depositItem(&myLocker, "14101941", item1);
	displayItemList(myLocker);

	heavyItems.IL = getHeavyItems(&myLocker, &heavyItems, 1.00);
	displayItemList(myLocker);
	displayItemList(heavyItems);
	return 0;
}
