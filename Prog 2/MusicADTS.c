#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int minutes;
	int seconds;
} Duration;

typedef struct {
	char songName[20];
	char albumName[20];
	Duration length;
} Song;

typedef struct {
	char bandName[20];
	Song track[20];
} Band;

void addBand(Band listOfBands[], int *numBands) {
	int numSongs;

	printf("How many bands/artists that you like? ");
	scanf("%d", numBands);

	for (int i = 0; i < *numBands; i++) {
		printf("---------------------------------------\n");
		printf("<Artist %d>\n", i + 1);

		printf("Artist/Band Name: ");
		scanf(" %[^\n]s", listOfBands[i].bandName);

		printf("Number of Songs: ");
		scanf("%d", &numSongs);

		for (int j = 0; j < numSongs; j++) {
			printf("<Song %d>\n", j + 1);

			printf("Title: ");
			scanf(" %[^\n]s", listOfBands[i].track[j].songName);

			printf("Duration: ");
			scanf("%d:%d", &listOfBands[i].track[j].length.minutes, &listOfBands[i].track[j].length.seconds);

			printf("Album: ");
			scanf(" %[^\n]s", listOfBands[i].track[j].albumName);
		}
	}
	printf("\n\n");
}

void displayBands(Band listOfBands[], int numBands) {
	printf("<Favorite Bands>\n");
	for (int i = 0; i < numBands; i++) {
		int songCount = 0;
		int songSize = sizeof(listOfBands[i].track) / sizeof(listOfBands[i].track[0]);

		for (int j = 0; j < songSize; j++) {
			if (listOfBands[i].track[j].songName[0] != '\0') {
				songCount++;
			}
		}

		if (songCount) {
			printf("%d. %s - %d song\n", i + 1, listOfBands[i].bandName, songCount);
		} else {
			printf("%d. %s - %d songs\n", i + 1, listOfBands[i].bandName, songCount);
		}
	}
	printf("\n\n");
}

void displaySongs(Band listOfBands[], int numBands) {
	for (int i = 0; i < numBands; i++) {
		int songSize = sizeof(listOfBands[i].track) / sizeof(listOfBands[i].track[0]);

		printf("<%s Songs>\n", listOfBands[i].bandName);

		for (int j = 0; j < songSize; j++) {
			if (listOfBands[i].track[j].songName[0] != '\0') {
				printf("%d. %s - %d:%d - %s\n", j + 1, listOfBands[i].track[j].songName, listOfBands[i].track[j].length.minutes, listOfBands[i].track[j].length.seconds, listOfBands[i].track[j].albumName);
			}
		}
		printf("\n\n");
	}
}

void getMethod(int *userInput) {
	printf("---------------- MENU -----------------\n");
	printf("1. Add a band/artist\n");
	printf("2. Display all favorite band/artist\n");
	printf("3. Display all favorite songs they have\n");
	printf("4. Sort by Duration\n");
	printf("5. Sort by Year\n");
	printf("6. Exit\n");
	printf("---------------------------------------\n\n");

	printf("Enter option: ");
	scanf("%d", userInput);
}

int main(void) {
	int userInput;
	int numBands;

	Band listOfBands[20];

	do {
		getMethod(&userInput);
		switch (userInput) {
			case 1:
				addBand(listOfBands, &numBands);
				break;
			case 2:
				displayBands(listOfBands, numBands);
				break;
			case 3:
				displaySongs(listOfBands, numBands);
				break;
			case 4:
				// sortByDuration();
				break;
			case 5:
				// sortByYear();
				break;
			case 6:
				break;
			default:
				break;
		}
	} while (userInput != 6);

	return 0;
}