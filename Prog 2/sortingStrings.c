#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct temp {
	char fname[20];
	char lname[20];
	char program[20];
	int age;
};

struct info {
	struct temp var[5];
};

struct temp *sortByProgramAsc(struct temp *var) {
	struct temp tempvar;
	struct temp *tempPtr = (struct temp *)malloc(5 * sizeof(struct temp));
	int x, y;
	for (x = 0; x < 4; x++) {
		for (y = x + 1; y < 5; y++) {
			if (strcmp(var[x].program, var[y].program) > 0) {
				tempvar = var[x];
				var[x] = var[y];
				var[y] = tempvar;
			}
		}
	}
	memcpy(tempPtr, var, (5 * sizeof(struct temp)));
	return tempPtr;
}
struct info sortByLastNameAsc(struct temp *var) {
	struct temp tempvar;
	struct info tempvar2;

	for (int x = 0; x < 4; x++) {
		for (int y = x + 1; y < 5; y++) {
			if (strcmp(var[x].lname, var[y].lname) > 0) {
				tempvar = var[x];
				var[x] = var[y];
				var[y] = tempvar;
			}
		}
	}
	for (int y = 0; y < 5; y++) {
		tempvar2.var[y] = var[y];
	}
	return tempvar2;
}
void printThisOne(struct temp *var) {
	int x;
	for (x = 0; x < 5; x++) {
		printf("%s\t%s\t\t%s\t%i\n", var[x].fname, var[x].lname, var[x].program, var[x].age);
	}
}
void printThisTwo(struct info tempvar) {
	int x;
	for (x = 0; x < 5; x++) {
		printf("%s\t%s\t\t%s\t%i\n", tempvar.var[x].fname, tempvar.var[x].lname, tempvar.var[x].program, tempvar.var[x].age);
	}
}

int main(void) {
	struct temp var[5] = {
		{"Chris", "Maderazo", "BSCOMPE", 51},
		{"John", "Duterte", "BSIT", 30},
		{"asdf", "qwer", "BSCS", 19},
		{"wert", "sdfg", "BSIT", 20},
		{"sdfg", "hdfgh", "BSCS", 30}
	};
	
	struct temp *var2 = sortByProgramAsc(var);
	printThisOne(var2);
	printf("\n");
	struct info var3 = sortByLastNameAsc(var);
	printThisTwo(var3);

	return 0;
}