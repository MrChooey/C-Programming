#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
} PersonList;

typedef struct node {
	Person P;
	struct node *link;
} *StackLList;

// |------------------------------------------------------------------------------------------------|
// | In a collection of voters stored in an array list of person, get all the voters living in a	|
// | specified city and store them into a Stack Linked List.										|
// |------------------------------------------------------------------------------------------------|

StackLList getVoters(PersonList voters, char *city) {
	StackLList V = NULL;
	int i;
	for (i = 0; i < voters.count; i++) {
		if (strcmp(voters.person[i].address.city, city) == 0) {
			StackLList temp = (StackLList)malloc(sizeof(struct node));
			if (temp != NULL) {
				temp->P = voters.person[i];
				temp->link = V;
				V = temp;
			}
		}
	}
	return V;
}