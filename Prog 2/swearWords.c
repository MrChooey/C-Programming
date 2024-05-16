#include <stdio.h>
#include <string.h>

void censor(char *word, int size) {
	for (int k = 0; k < size; k++) {
		if (k != 0 && k != size - 1) {
			word[k] = '*';
		}
	}
}

int main(void) {
	char string[100];
	char *swear[] = {"fk", "dk", "ct", "py"};

	printf("Write me a sentence: ");
	gets(string);

	printf("%s\n", string);

	char *word = strtok(string, " ");

	while (word != NULL) {
		int size = strlen(word);
		for (int k = 0; k < 4; k++) {
			if (word[0] == swear[k][0] && word[size - 1] == swear[k][1]) {
				censor(word, size);
			}
		}
		printf("%s ", word);
		word = strtok(NULL, " ");
	}

	return 0;
}
