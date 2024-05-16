#include <stdio.h>
#include <string.h>

void removeSpace(char str[]) {
	char *word = strtok(str, " ");

	int i = 0;

	// hello world mates
	while (word != NULL) {
		if (!i)
			strcpy(str, word);
		else
			strcat(str, word);

		word = strtok(NULL, " ");
		i++;
	}
}

int main(void) {
	char str[100];

	printf("Enter a string: ");
	gets(str);

	removeSpace(str);

	printf("Modified string: %s", str);

	return 0;
}