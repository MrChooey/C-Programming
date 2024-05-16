#include <stdio.h>

typedef struct {
	int octet1;
	int octet2;
	int octet3;
	int octet4;
} IP;

typedef struct {
	IP given;
	IP new;
	int hosts;
	int placement;
	int delta;
	int newBits;
	int prefix;
} Data;

void firstFormula(Data *input) {
	int newOctet;

	newOctet = input->delta * input->placement;

	if (newOctet > 256) {
		input->newBits = 9;
		return;
	} else
		input->new.octet4 = newOctet;
}

void secondFormula(Data *input) {
	double newOctet = (input->delta * input->placement) / 256.0;

	int wholeNum;

	for (int i = 0; i < 2; i++) {
		wholeNum = newOctet;

		if (newOctet > 256) {
			input->newBits = 17;
			break;
		}

		if (!(newOctet - wholeNum) && !i) {
			input->new.octet3 = newOctet;
			input->new.octet4 = 0;
			break;
		} else {
			if (!i) {
				input->new.octet3 = wholeNum;
				newOctet -= wholeNum;
				newOctet *= 256;
			} else
				input->new.octet4 = newOctet;
		}
	}
}

void thirdFormula(Data *input) {
	double newOctet = (input->delta * input->placement) / 65536.0;

	int wholeNum;

	for (int i = 0; i < 3; i++) {
		wholeNum = newOctet;

		if (!(newOctet - wholeNum) && !i) {
			input->new.octet3 = newOctet;
			input->new.octet4 = 0;
			break;
		} else {
			if (!i) {
				input->new.octet2 = wholeNum;
				newOctet -= wholeNum;
				newOctet *= 256;
			} else if (i == 1) {
				input->new.octet3 = wholeNum;
				newOctet -= wholeNum;
				newOctet *= 256;
			} else
				input->new.octet4 = newOctet;
		}
	}
}

int findPrefix(int hosts) {
	int binaryBits = 0;
	int toTheNth = 1;

	for (int i = 0;; i++) {
		binaryBits++;
		toTheNth *= 2;
		if (hosts <= toTheNth - 2 && hosts > toTheNth / 2) break;
	}
	return 32 - binaryBits;
}

void calculate(Data *input) {
	if (!input->prefix) input->prefix = findPrefix(input->hosts);

	input->delta = 256;

	for (int i = 0; i < input->prefix; i++) {
		if (input->delta == 2) {
			input->delta = 256;
			continue;
		}
		input->delta /= 2;
	}

	int defaultBits;

	if (input->given.octet1 < 128) defaultBits = 8;
	else if (input->given.octet1 >= 128 && input->given.octet1 < 192) defaultBits = 16;
	else defaultBits = 24;

	input->newBits = input->prefix - defaultBits;

	input->new = input->given;

	if (input->newBits <= 8) firstFormula(input);
	if (input->newBits > 8 && input->newBits <= 16) secondFormula(input);
	if (input->newBits > 16) thirdFormula(input);
}

int main(void) {
	Data input;

	printf("\n ---- IP Subnet Finder ----\n");

	printf("Enter given IP: ");
	scanf("%d.%d.%d.%d", &input.given.octet1, &input.given.octet2, &input.given.octet3, &input.given.octet4);

	char choice;

	printf("Given with prefix? (y/n): ");
	scanf(" %c", &choice);

	input.prefix = 0;

	if (choice == 'y' || choice == 'Y') {
		printf("Enter prefix: ");
		scanf("%d", &input.prefix);
	}

	printf("Enter number of hosts: ");
	scanf("%d", &input.hosts);

	printf("Subnet Placement (Nth): ");
	scanf("%d", &input.placement);

	calculate(&input);

	printf("S%d = %d.%d.%d.%d\n\n", input.placement, input.new.octet1, input.new.octet2, input.new.octet3, input.new.octet4);

	do {
		printf("Enter more subnets? (y/n): ");
		scanf(" %c", &choice);

		switch(choice) {
			case 'y':
				printf("Subnet Placement (Nth): ");
				scanf("%d", &input.placement);

				calculate(&input);

				printf("S%d = %d.%d.%d.%d\n\n", input.placement, input.new.octet1, input.new.octet2, input.new.octet3, input.new.octet4);
				break;
			case 'n':
				printf("Exiting...\n");
				break;
			default:
				printf("Invalid input!\n");
				break;
		}
	} while (choice == 'y' || choice == 'Y');

	return 0;
}