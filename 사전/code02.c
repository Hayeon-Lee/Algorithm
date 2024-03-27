#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int searchKey(int arr[], int key, int N);

int main() {
	int N, key, *arr, answer = 0;

	scanf("%d %d", &N, &key);
	arr = (int *)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	answer = searchKey(arr, key, N);
	printf("%d", answer);

	free(arr);
	return 0;
}

int searchKey(int arr[], int key, int N) {
	int l = 0, r = N - 1;

	while (l <= r) {
		int mid = (l + r) / 2;

		if (arr[mid] < key && mid == N - 1) return N;
		if (arr[mid] > key && mid == 0) return mid;

		if (key == arr[mid]) return mid;

		else {
			if (key < arr[mid]) r = mid - 1;
			else if(key > arr[mid])l = mid + 1;
		}
	}
} <- if/else if/else로 구현 가능
