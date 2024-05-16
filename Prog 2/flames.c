// I did not write this xd
#include <stdio.h>

int main(void) {
	char name1[20], name2[20];
	char flames[6] = {'F', 'L', 'A', 'M', 'E', 'S'};

	printf("---- FLAMES ----\n");

	printf("Enter the first name: ");
	scanf("%s", name1);

	printf("Enter the second name: ");
	scanf("%s", name2);

	for (int i = 0; name1[i] != '\0'; i++) {
		for (int j = 0; name2[j] != '\0'; j++) {
			if (name1[i] == name2[j]) {
				name1[i] = name2[j] = ' ';
			}
		}
	}

	int count = 0;

	for (int i = 0; name1[i] != '\0'; i++) 
		if (name1[i] != ' ') count++;

	for (int i = 0; name2[i] != '\0'; i++) 
		if (name2[i] != ' ') count++;

	int length = 6;

	for (int i = 0; i < 6; i++) {
		int index = count % length;
		if (index == 0) index = length;
		for (int j = index - 1; j < length - 1; j++) {
			flames[j] = flames[j + 1];
		}
		length--;
		if (length == 1) break;
	}

	if (flames[0] == 'F') printf("The relationship is: Friends\n");
	else if (flames[0] == 'L') printf("The relationship is: Lovers\n");
	else if (flames[0] == 'A') printf("The relationship is: Affection\n");
	else if (flames[0] == 'M') printf("The relationship is: Marriage\n");
	else if (flames[0] == 'E') printf("The relationship is: Enemies\n");
	else if (flames[0] == 'S') printf("The relationship is: SEX!!!!\n");

	return 0;
}