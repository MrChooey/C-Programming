#include <stdio.h>
#define MAX 20

typedef struct {
	int open;
	int close;
	float value1;
	float value2;
	char operation;
} Stack;

float calculate(Stack *values, char equation[]) {
	float tempStack[MAX];

	float tempResult = 0;
	int current = 0;

	values->value1 = 0;
	values->value2 = 0;

	// ((5 * 2) / 2)
	for (int i = 0; equation[i] != '\0'; i++, current++) {
		tempStack[current] = equation[current];
		if (equation[i] == '(') {
			values->open = i;
		} else if (equation[i] == ')') {
			values->close = i;

			for (int j = values->open; j < values->close; j++) {
				if ((equation[j] > 47 && equation[j] < 58) && !values->value1) {
					values->value1 = equation[j] - 48;
				} else if ((equation[j] > 47 && equation[j] < 58) && values->value1) {
					values->value2 = equation[j] - 48;
				} else if (equation[j] == '+' || equation[j] == '-' || equation[j] == '*' || equation[j] == '/') {
					values->operation = equation[j];
				}
			}

			if (values->operation == '+') {
				tempResult = values->value1 + values->value2;
			} else if (values->operation == '-') {
				tempResult = values->value1 - values->value2;
			} else if (values->operation == '*') {
				tempResult = values->value1 * values->value2;
			} else if (values->operation == '/') {
				tempResult = values->value1 / values->value2;
			}

			current = values->open;
			tempStack[current] = tempResult;
			current++;

			for (int k = 0; tempStack[k] != tempResult; k++) {
				if (tempStack[k] == '(') values->open = k;
			}

		}
	}

	tempResult = tempStack[0];

	return tempResult;
}

int main(void) {
	char equation[MAX];
	Stack values;

	printf("Enter operation: ");
	scanf("%s", equation);

	printf("Result: %.2f", calculate(&values, equation));

	return 0;
}