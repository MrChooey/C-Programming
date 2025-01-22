#include <stdio.h>
#define MAX 6

void bubbleSort(int arr[]) {
	for (int i = 0; i < MAX; i ++) {
		for (int j = 0; j < MAX; j++) {
			if (arr[j] > arr[j + 1]) {
				int temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	printf("Bubble Sort:");
	for (int i = 0; i < MAX; i++) printf(" %d", arr[i]);
}

int main(void) {
	int arr[] = {5, 3, 2, 6, 1, 4};

	printf("Unsorted List: {5, 3, 2, 6, 1, 4}\n");
	bubbleSort(arr);

	return 0;
}