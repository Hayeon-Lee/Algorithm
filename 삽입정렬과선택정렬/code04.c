#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

int * selectsort(int *selectarr, int n);
int * insertsort(int *insertarr, int n);
int * bubblesort(int *arr, int n);

int main() {
	LARGE_INTEGER ticksPerSec;
	LARGE_INTEGER start, end, diff;
	int n = 0, *selectarr, *insertarr;

	scanf("%d", &n);
	selectarr = (int *)malloc(sizeof(int)*n);
	insertarr = (int *)malloc(sizeof(int)*n);

	srand(time(NULL));

	for (int i = 0; i < n; i++) {
		selectarr[i] = rand();
		insertarr[i] = selectarr[i];
	}

	selectarr = bubblesort(selectarr, n);
	insertarr = bubblesort(insertarr, n);

	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	selectarr = selectsort(selectarr, n);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%12f ms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));
	
	QueryPerformanceFrequency(&ticksPerSec);
	QueryPerformanceCounter(&start);
	insertarr = insertsort(insertarr, n);
	QueryPerformanceCounter(&end);

	diff.QuadPart = end.QuadPart - start.QuadPart;
	printf("%12f ms\n", ((double)diff.QuadPart / (double)ticksPerSec.QuadPart));

	free(selectarr);
	free(insertarr);

	return 0;
}

int * selectsort(int *selectarr, int n)
{
	int max = 0, index = 0, temp = 0;

	for (int i = n - 1; i >= 0; i--) {
		max = selectarr[0];
		index = 0;
		for (int j = 1; j <= i; j++) {
			if (selectarr[j] > max) {
				max = selectarr[j];
				index = j;
			}
		}
		temp = selectarr[i];
		selectarr[i] = selectarr[index];
		selectarr[index] = temp;
	}

	return selectarr;
}
int * insertsort(int *insertarr, int n)
{
	int temp = 0, index = 0, box, j;

	for (int i = 1; i < n; i++) {
		box = insertarr[i];
		j = i - 1;
		while (j >= 0 && insertarr[j] > box) {
			insertarr[j + 1] = insertarr[j];
			j -= 1;
		}
		insertarr[j + 1] = box;
	}

	return insertarr;
}
int * bubblesort(int *arr, int n)
{
	int temp = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++) {
			if (arr[j] < arr[j + 1]) {
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
		}
	}

	return arr;
}
