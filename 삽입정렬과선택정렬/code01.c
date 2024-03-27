#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int * insertionSort(int *arr, int n); //삽입정렬

int main()
{
	int *arr = NULL, n = 0;

	scanf("%d", &n); //배열 크기 입력받기

	arr = (int *)malloc(sizeof(int)*n); //n크기의 배열 동적할당하기
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]); //배열에 숫자 저장하기

	insertionSort(arr, n);

	for (int i = 0; i < n; i++) printf("%d ", arr[i]);
}

int * insertionSort(int *arr, int n)
{
	int temp = 0, index = 0;

	for (int i = 1; i < n; i++) { //배열의 크기만큼 반복해야함
		for (int j = 0; j < i; j++) { //i까지만 반복한다 == 앞에서부터 순차적으로 정렬한다
			if (arr[j]<=arr[i] && arr[j + 1]>arr[i]) {
				temp = arr[i];
				index = j;
				for (int k = i; k > index; k--) arr[k] = arr[k - 1];
				arr[index + 1] = temp;
			}
			else if (j == 0 && arr[i] < arr[j]) { //5 4 3 2 1 같이 가장 큰 수가 제일 앞에 있을 때 
				temp = arr[i];
				index = j;
				for (int k = i; k >= index; k--) arr[k] = arr[k - 1];
				arr[index] = temp;
			}
		}
	}

	return arr;
}
