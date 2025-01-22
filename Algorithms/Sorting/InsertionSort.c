#include <stdio.h>
#define MAX 6

void insertionSort(int arr[]) {
	for (int i = 1; i < MAX; i++) {
		int temp = arr[i];
		int j = i;
		while (j > 0 && arr[j - 1] > temp) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}

	printf("Insertion Sort:");
	for (int i = 0; i < MAX; i++) printf(" %d", arr[i]);
}

int main(void) {
	int arr[] = {5, 3, 2, 6, 1, 4};

	printf("Unsorted List: {5, 3, 2, 6, 1, 4}\n");
	insertionSort(arr);

	return 0;
}