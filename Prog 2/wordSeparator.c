// TODO: Can be improved pls strtok();

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void getSentence(char *sentence) {
	printf("Write me a sentence: ");
	gets(sentence);
}

void printWords(char **words, int size) {
	printf("\n");
	for (int i = 0; i < size; i++) {
		printf("Word %d: %s\n", i + 1, words[i]);
	}
}

void separate(char *sentence, char **words) {

	int x = 0;
	int y = 0;
	int z = longestWord(sentence);

	for (int i = 0; sentence[i] != '\0'; i++) {
		if (x == 0) {
			words[y] = malloc(sizeof(char) * z);
		}
		if (sentence[i] == ' ') {
			words[y][x] = '\0';
			y++;
			x = 0;
		} else {
			words[y][x] = sentence[i];
			x++;
		}
	}
	words[y][x] = '\0';
}

int wordLen(char sentence[]) {
	int len = (*sentence != ' ') ? 1 : 0;

	for (int i = 0; sentence[i] != '\0'; i++)
		if (sentence[i] == ' ') len++;

	return len;
}

int longestWord(char sentence[]) {
	int len = 0;
	int currentWord = 0;

	for (int i = 0; sentence[i] != '\0'; i++) {
		if (sentence[i] != ' ')
			currentWord++;
		else
			currentWord = 0;
		if (currentWord > len) len = currentWord;
	}

	return len;
}

int main(void) {
	char sentence[200];

	getSentence(sentence);

	int size = wordLen(sentence);

	char **words = malloc(sizeof(char *) * size);

	printf("%s", sentence);

	separate(sentence, words);
	printWords(words, size);

	for (int i = 0; i < size; i++) {
		free(words[i]);
	}

	free(words);

	return 0;
}