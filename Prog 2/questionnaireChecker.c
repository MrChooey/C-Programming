#include <stdio.h>
#include <string.h>

typedef struct {
	char fName[20];
	char lName[20];
	char MI;
} Person;

typedef struct {
	Person name;
	char answers[10];
	int score;
} StudentInfo;

void checkAnswers(StudentInfo *students, char *answerKey) {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 10; j++) {
			if (students[i].answers[j] == answerKey[j])
				students[i].score++;
		}
	}
}

void searchStudent(StudentInfo *students, char *searchName) {
	for (int i = 0; i < 5; i++) {
		if (strcmp(students[i].name.fName, searchName) == 0) {
			printf("\nStudent's Answers: %s\n", students[i].answers);
			printf("Score: %d\n", students[i].score);
			break;
		}
	}
}

int main(void) {
	char answerKey[10];
	char searchName[20];

	StudentInfo students[5] = {
		{{"Ron", "Ramas", 'G'}, "TTFTFTFTFT", 0},
		{{"Reynat", "Daganta", 'B'}, "FTFTFTFTFT", 0},
		{{"Destin", "Decarma", 'C'}, "TFTFTFTFTF", 0},
		{{"Daphne", "Surigao", 'D'}, "FTFTFTFTFT", 0},
		{{"Railey", "Escandor", 'E'}, "TFTFTFTFTF", 0}
	};

	printf("\n\n###### Questionnaire Checker ######\n\n");

	printf("Enter the correct answers: ");
	scanf("%s", answerKey);

	checkAnswers(students, answerKey);

	printf("Enter name of student to search: ");
	scanf("%s", searchName);

	searchStudent(students, searchName);

	printf("\n########## End of Program ##########\n\n");

	return 0;
}