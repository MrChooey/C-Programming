#include <stdio.h>
#define MAX 10

void binarySearch(int arr[], int data) {
	int left = 0;
	int right = MAX - 1;
	int mid = right / 2;

	while (mid != data && left < right) {
		if (data < mid) {
			right = mid;
			mid = (left + right) / 2;
		}
		else if (data > mid) {
			left = mid;
			mid = (left + right) / 2;
		}
	}
}