#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int searchKey(int arr[], int key, int l, int r);

int main() {
	int N, key, *arr, answer = 0;

	scanf("%d %d", &N, &key);
	arr = (int *)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

	answer = searchKey(arr, key, 0, N-1);
	printf("%d", answer);

	free(arr);
	return 0;
}

int searchKey(int arr[], int key, int l, int r) {
	if (l > r) return -1; //범위 넘어감

	int middle = (l + r) / 2; 

	if (arr[middle] < key) { 
		if (arr[middle + 1] > key) return middle; //key가 사전에 없는데, 그 다음 원소가 키보다 클 때
		else if (middle==0 && r==0) return -1; //해당 key보다 작은 원소가 사전에 없을 때
	}

	if (arr[middle] < key && middle == r) return r; //가장 끝까지 원소를 봤는데도 key보다 모두 작을 때

	if (key == arr[middle]) return middle;
	else if (key < arr[middle]) return searchKey(arr, key, l, middle - 1);
	else return searchKey(arr, key, middle + 1, r);
}
