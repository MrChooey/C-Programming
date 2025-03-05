#include <stdio.h>
#define MAX 6

void shellSort(int arr[]) {
	int gap = MAX / 2;
	while (gap > 0) {
		for (int i = gap; i < MAX; i++) {
			int temp = arr[i];
			int j = i;
			while (j >= gap && arr[j - gap] > temp) {
				arr[j] = arr[j - gap];
				j -= gap;
			}
			arr[j] = temp;
		}
		gap /= 2;
	}

	printf("Shell Sort:");
	for (int i = 0; i < MAX; i++) printf(" %d", arr[i]);
}

int main(void) {
	int arr[] = {5, 3, 2, 6, 1, 4};

	printf("Unsorted List: {5, 3, 2, 6, 1, 4}\n");
	shellSort(arr);

	return 0;
}