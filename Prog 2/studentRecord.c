#include <stdio.h>
#include <string.h>

typedef struct {
	char fname[20];
	char MI;
} PersonName;

typedef struct {
	int age;
	PersonName name;
	int yrLevel;
} Person;

typedef struct {
	Person student[5];
	int count;
} PersonList;

typedef struct {
	PersonList classList;
	PersonList firstYears;	
	PersonList secondYears;
} SchoolRecord;

void getMethod(int *userInput) {
	printf("Student Management System\n");
	printf("1. Add Student\n");
	printf("2. Remove Student\n");
	printf("3. Display Students\n");
	printf("4. Display First Year Students\n");
	printf("5. Display Second Year Students\n");
	printf("6. Exit\n\n");

	printf("Enter option: ");
	scanf("%d", userInput);
}

void addStudent(SchoolRecord *usc) {
	Person temp;

	int studentCount = usc->classList.count;

	printf("Enter student's first name: ");
	scanf("%s", usc->classList.student[studentCount].name.fname);

	printf("Enter student's middle initial: ");
	scanf(" %c", &usc->classList.student[studentCount].name.MI);

	printf("Enter student's age: ");
	scanf("%d", &usc->classList.student[studentCount].age);

	printf("Enter student's year level: ");
	scanf("%d", &usc->classList.student[studentCount].yrLevel);

	usc->classList.count++;

	if (usc->classList.student[studentCount].yrLevel == 1) {
		usc->firstYears.student[usc->firstYears.count] = usc->classList.student[studentCount];
		usc->firstYears.count++;
	} else if (usc->classList.student[studentCount].yrLevel == 2) {
		usc->secondYears.student[usc->secondYears.count] = usc->classList.student[studentCount];
		usc->secondYears.count++;
	}

	for (int i = 0; i < studentCount + 1; i++) {  // may be possible logical error here
		for (int j = 0; j < studentCount; j++) {
			if (strcmp(usc->classList.student[j].name.fname, usc->classList.student[j + 1].name.fname) > 0) {
				temp = usc->classList.student[j];
				usc->classList.student[j] = usc->classList.student[j + 1];
				usc->classList.student[j + 1] = temp;
			}
		}
	}

	printf("Student added.\n\n");
}

void removeStudent(SchoolRecord *usc) {
	int studentCount = usc->classList.count;

	char studentName[20];
	char studentMI;

	printf("Enter student's first name and middle initial: ");
	scanf("%s %c", studentName, &studentMI);

	//possible logical error in this for loop
	for (int i = 0; i < studentCount; i++) {
		if (!strcmp(usc->classList.student[i].name.fname, studentName)
		&& usc->classList.student[i].name.MI == studentMI) {
			for (int j = i; j < studentCount; j++) {
				usc->classList.student[j] = usc->classList.student[j + 1];
			}
			usc->classList.count--;

			for (int j = i; j < usc->firstYears.count; j++) {
				usc->firstYears.student[j] = usc->firstYears.student[j + 1];
			}
			usc->firstYears.count--;

			for (int j = i; j < usc->secondYears.count; j++) {
				usc->secondYears.student[j] = usc->secondYears.student[j + 1];
			}
			usc->secondYears.count--;
		}
	}
	printf("Student removed.\n\n");
}

void displayStudents(SchoolRecord *usc) {
	for (int i = 0; i < usc->classList.count; i++) {
		printf("Student %d: %s\n", i + 1, usc->classList.student[i].name.fname);
		printf("Age: %d\n", usc->classList.student[i].age);
		printf("Year Level: %d\n\n", usc->classList.student[i].yrLevel);
	}
}

void displayFirstYearStudents(SchoolRecord *usc) {
	int studentCount = usc->firstYears.count;

	Person temp;

	for (int i = 0; i < studentCount; i++) {
		for (int j = 0; j < studentCount - 1; j++) { // I DUNNO WHY THIS WORKS!!!!
			if (strcmp(usc->firstYears.student[j].name.fname, usc->firstYears.student[j + 1].name.fname) > 0) {
				temp = usc->firstYears.student[j];
				usc->firstYears.student[j] = usc->firstYears.student[j + 1];
				usc->firstYears.student[j + 1] = temp;
			}
		}
	}

	printf("<First year students>\n");

	for (int i = 0; i < studentCount; i++) {
		printf("%d. %s %c.\n", i + 1, usc->firstYears.student[i].name.fname, usc->firstYears.student[i].name.MI);
	}
	printf("\n");
}

void displaySecondYearStudents(SchoolRecord *usc) {
	int studentCount = usc->secondYears.count;

	Person temp;

	for (int i = 0; i < studentCount; i++) {	
		for (int j = 0; j < studentCount - 1; j++) {
			if (strcmp(usc->secondYears.student[j].name.fname, usc->secondYears.student[j + 1].name.fname) > 0) {
				temp = usc->secondYears.student[j];
				usc->secondYears.student[j] = usc->secondYears.student[j + 1];
				usc->secondYears.student[j + 1] = temp;
			}
		}
	}

	printf("<Second Years>\n");

	for (int i = 0; i < studentCount; i++) {
		printf("%d. %s %c.\n", i + 1, usc->secondYears.student[i].name.fname, usc->secondYears.student[i].name.MI);
	}
	printf("\n");
}

int main(void) {
	int userInput;

	SchoolRecord usc;
	usc.classList.count = 0;
	usc.firstYears.count = 0;
	usc.secondYears.count = 0;

	do {
		getMethod(&userInput);
		switch (userInput) {
			case 1:
				addStudent(&usc);
				break;
			case 2:
				removeStudent(&usc);
				break;
			case 3:
				displayStudents(&usc);
				break;
			case 4:
				displayFirstYearStudents(&usc);
				break;
			case 5:
				displaySecondYearStudents(&usc);
				break;
			case 6:
				printf("Exiting...\n");
				break;
			default:
				break;
		}
	} while (userInput != 6);

	return 0;
}