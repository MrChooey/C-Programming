#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct {
	char city[16];
	int zip;
} Address;

typedef struct {
	int id;
	char name[16];
	Address address;
} Person;

typedef struct {
	Person *person;
	int count;
	int max;
} PersonDict;

typedef struct node {
	Person P;
	struct node *link;
} *NodePtr;

typedef struct {
	NodePtr data[MAX];
	int count;
} OpenPersonDict;

typedef char String[16];

String *getNames(OpenPersonDict list, String city) {
	String *names = (String*)malloc(sizeof(String) * list.count);
	
	if (names != NULL) {
		int i, j;
		NodePtr trav;
		for (i = 0, j = 0; i < list.count; i++) {
			for (trav = list.data[i]; trav != NULL; trav = trav->link) {
				if (trav->P.id >= 1 && trav->P.id <= 100 && (strcmp(trav->P.address.city, city) == 0)) {
					strcpy(names[j], trav->P.name);
					j++;
				}
			}
		}
		strcpy(names[j], " ");
	}

	return names;
}