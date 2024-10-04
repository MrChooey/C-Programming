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

int hash(int data);

// |------------------------------------------------------------------------------------------------|
// | Create a function that returns an array of names of all persons in the OpenPersonDictionary	|
// | that has an id from 1 - 100 and lives in the specified city. Use an empty string to terminate	|
// | the array of names.																			|
// |------------------------------------------------------------------------------------------------|

String *getNames(OpenPersonDict list, String city) {
	String *names = (String *)malloc(sizeof(String) * list.count);

	int i, j;
	if (names != NULL) {
		NodePtr trav;
		for (i = 1, j = 0; i <= 100; i++) {
			int index = hash(i);
			for (trav = list.data[index]; trav != NULL; trav = trav->link) {
				if (trav->P.id == i && (strcmp(trav->P.address.city, city) == 0)) {
					strcpy(names[j++], trav->P.name);
				}
			}
		}
		strcpy(names[j++], "");
	}
	names = (String*)realloc(sizeof(String) * j);

	return names;
}