// insertion sort
#include <stdio.h>
#include <stdlib.h>

void insert(int arr[], int size) {
	for (int i = 1; i < size; i++) {
		int temp = arr[i];
		int j = i;

		while (j > 0 && arr[j - 1] > temp) {
			arr[j] = arr[j - 1];
			j--;
		}
		arr[j] = temp;
	}
}

int getSize() {
	int size;

	printf("Array size: ");
	scanf("%d", &size);

	return size;
}

int *getNums(int size) {
	int *arr = (int *)malloc(size * sizeof(int));

	for (int i = 0; i < size; i++) {
		printf("Enter arr[%d]: ", i);
		scanf("%d", &arr[i]);
	}

	return arr;
}

int main(void) {
	int size = getSize();
	int *arr = getNums(size);

	insert(arr, size);

	for (int i = 0; i < size; i++) printf("%d ", arr[i]);

	return 0;
}
