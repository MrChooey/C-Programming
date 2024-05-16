//TODO: Transform code from stack to another ADT / Add the last two functions

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef char String[20];

typedef struct {
	int hour;
	int minute;
} MyTime;

typedef struct {
	char type; // A - Motorcycle ; B - Car, Sedan, UV ; C - Truck
	String plateNum;
	String color;
	String model;
} Vehicle;

typedef struct {
	Vehicle vehicle;
	MyTime timeIn;
	MyTime timeOut;
} ParkingInfo;

typedef struct {
	ParkingInfo *slot;
	int count;
	int max;
} ParkingArea, ParkingHistory;

Vehicle createVehicle() {
	Vehicle vehicle;

	printf("Vehicle Type:\n");
	printf("[A - Motorcycle : B - Car, Sedan, UV : C - Truck]\n\n");

	printf("Enter vehicle type: ");
	scanf(" %c", &vehicle.type);

	printf("Enter vehicle plate number: ");
	scanf("%s", vehicle.plateNum);

	printf("Enter vehicle color: ");
	scanf("%s", vehicle.color);

	printf("Enter vehicle model: ");
	scanf("%s", vehicle.model);

	printf("\n");

	return vehicle;
}

MyTime createMyTime() {
	MyTime time;

	printf("\n\n");

	printf("Enter time-in: ");
	scanf("%d:%d", &time.hour, &time.minute);

	printf("\n\n");

	return time;
}

ParkingInfo createParkingInfo() {
	ParkingInfo info;

	MyTime temp = createMyTime();
	info.timeIn = temp;

	Vehicle temp2 = createVehicle();
	info.vehicle = temp2;

	return info;
}

void initParkingArea(ParkingArea *area) {
	printf("Enter Parking Capacity: ");
	scanf("%d", &area->max);

	area->slot = malloc(sizeof(area->max));

	for (int i = 0; i < area->max; i++) {
		area->slot[i].vehicle.type = ' ';
	}

	printf("\nInitializing...\n");
}

void displayParkingArea(ParkingArea *area) {
	printf("\nNO SLOT | STATUS\n");

	for (int i = 0; i < area->max; i++) {
		if (area->slot[i].vehicle.type == ' ')
			printf("%d\t| available\n", i);
		else {
			printf("%d\t| %s - ", i, area->slot[i].vehicle.model);
			printf("%s - ", area->slot[i].vehicle.color);
		}

		if (area->slot[i].vehicle.type == 'A') printf("Motorcycle\n");
		else if (area->slot[i].vehicle.type == 'B') printf("Car/Sedan/UV\n");
		else if (area->slot[i].vehicle.type == 'C') printf("Truck\n");
	}
}

// Custom Function
void displayMethod(int *choice) {
	printf("\n######### PARKING SYSTEM #########\n");
	printf("1.) Check in vehicle\n");
	printf("2.) Check out vehicle\n");
	printf("3.) Display parking space\n");
	printf("4.) Exit\n");
	printf("##################################\n\n");

	printf("Enter option: ");
	scanf("%d", choice);
}

// !! ERROR HERE !!
void printParkingReceipt(ParkingInfo *vehicleRec) {
	printf("\nParking Receipt: \n");

	printf("TYPE: ");

	if (vehicleRec->vehicle.type == 'A') printf("Motorcycle\n");
	else if (vehicleRec->vehicle.type == 'B') printf("Car/Sedan/UV\n");
	else if (vehicleRec->vehicle.type == 'C') printf("Truck\n");

	printf("VEHICLE: %s - %s - %s\n", vehicleRec->vehicle.plateNum, vehicleRec->vehicle.color, vehicleRec->vehicle.model);
	printf("TIME IN: %d:%d\n", vehicleRec->timeIn.hour, vehicleRec->timeIn.minute);
	printf("TIME OUT: %d:%d\n", vehicleRec->timeOut.hour, vehicleRec->timeOut.minute);

	/* TOTAL TIME: XX.XX hours
  Initial Charge (first 3 hours): Php xx.xx
  Additional Charge (after 3 hours): Php xx.xx
  Total Charge: Php xx.xx */
}


bool addParkIn(ParkingArea *area, ParkingInfo new) {
	if (area->count >= area->max) return false;
	if (area->slot[area->count].vehicle.type != ' ') return false;

	area->slot[area->count] = new;
	area->count++;

	return true;
}

bool checkOutVehicle(ParkingArea *area, ParkingHistory *record) {
	if (area->slot[area->count - 1].vehicle.type == ' ') return false;

	printf("\nChecking out...\n\n");

	printf("Enter time-out: ");
	scanf("%d:%d", &area->slot[area->count - 1].timeOut.hour, &area->slot[area->count - 1].timeOut.minute);

	record->slot[record->count] = area->slot[area->count];
	record->count++;

	area->slot[area->count - 1].vehicle.type = ' ';
	area->count--;

	return true;
}

ParkingHistory createParkingHistory() {
	ParkingHistory record;

	record.slot = calloc(20, sizeof(ParkingInfo));
	record.count = 0;
	record.max = 20;

	return record;
}

int main(void) {
	ParkingArea area;
	ParkingInfo new;

	area.count = 0;

	ParkingHistory record = createParkingHistory();

	initParkingArea(&area);
	
	int choice;

	do {
		displayMethod(&choice);
		switch(choice) {
			case 1:
				new = createParkingInfo();

				if (addParkIn(&area, new)) printf("Vehicle Recorded...!\n");
				else printf("Parking Space Full...!\n");

				break;
			case 2:
				if (checkOutVehicle(&area, &record)) {
					printf("\nParking %d checked out...!\n", area.count);
					printParkingReceipt(&record.slot[record.count - 1]);
				}
				else printf("\nParking already empty...!\n");

				break;
			case 3:
				displayParkingArea(&area);
				break;
			case 4:
				printf("\nExiting...");
				break;
			default:
			printf("\nInvalid Input. Please Try Again...\n");
				break;
		}
	} while(choice != 5);

	return 0;
}