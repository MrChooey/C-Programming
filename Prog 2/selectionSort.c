#include <stdio.h>

int main(void) {
	int arr[] = {5, 2, 1, 4, 3, 6};

	for (int i = 0; i < 6; i++) {
		int temp = arr[i];
		int index = i;

		for (int j = i; j < 6; j++) {
			if (arr[j] < temp) {
				temp = arr[j];
				index = j;
			}
		}

		arr[index] = arr[i];
		arr[i] = temp;
	}

	for (int i = 0; i < 6; i++) printf("%d ", arr[i]);

	return 0;
}
