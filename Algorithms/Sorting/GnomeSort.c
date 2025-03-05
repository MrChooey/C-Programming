#include <stdio.h>
#define MAX 6

void gnomeSort(int arr[]) {
	for (int i = 0; i < MAX;) {
		if (arr[i - 1] > arr[i] && i != 0) {
			int temp = arr[i - 1];
			arr[i - 1] = arr[i];
			arr[i] = temp;

			i--;
		} else i++;
	}

	printf("Gnome Sort:");
	for (int i = 0; i < MAX; i++) printf(" %d", arr[i]);
}

int main(void) {
	int arr[] = {5, 3, 2, 6, 1, 4};

	printf("Unsorted List: {5, 3, 2, 6, 1, 4}\n");
	gnomeSort(arr);

	return 0;
}