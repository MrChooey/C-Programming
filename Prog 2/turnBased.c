#include <stdio.h>
#include <stdlib.h>

typedef struct {
	char name[20];
	int health;
	int defense;
} Hero;

int main(void) {
	Hero *hero1 = malloc(sizeof(Hero));

	printf("Enter hero name: ");
	scanf("%s", (*hero1).name);

	printf("Enter health: ");
	scanf("%d", &hero1->health);

	printf("Enter defense: ");
	scanf("%d", &(*hero1).defense);

	int atk;
	char move;

	do {
		printf("Move: ");
		scanf(" %c %d", &move, &atk);

		switch (move) {
			case 'A':
				if (atk - hero1->defense < 0)
					hero1->health -= 0;
				else
					hero1->health -= atk - hero1->defense;

				if (hero1->health <= 0) {
					printf("%s has fallen.", hero1->name);
					return 0;
				}

				printf("%s current health - %d\n", hero1->name, hero1->health);

				break;
			case 'S':
				printf("I Surrender!");
				return 0;
		}
	} while (1);
}
