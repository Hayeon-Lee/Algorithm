#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void upHeap(int H[], int i);
void downHeap(int H[], int i, int n);
void insertitem(int H[], int n, int key);
void removeMax(int H[], int n);
void printHeap(int H[], int n);

int main()
{
	char order = 'a';
	int *H, n = 0, key = 0;

	H = (int *)malloc(sizeof(int) * 101);
	H[0] = 0;

	while (order != 'q') {
		scanf("%c", &order);

		if (order == 'i') {
			scanf("%d", &key);
			insertitem(H, n, key);
			n++;
		}

		else if (order == 'd'){
			removeMax(H, n);
			n--;
		}

		else if (order == 'p' && n > 0) printHeap(H, n);

		else if (order == 'q') break;
	}

	free(H);
	return 0;
}

void upHeap(int H[], int i)
{
	int temp = 0;

	if (i <= 1) return;

	if (H[i] >= H[i / 2]) {
		temp = H[i / 2];
		H[i / 2] = H[i];
		H[i] = temp;

		i /= 2;
		upHeap(H, i);
	}
}

void downHeap(int H[], int i, int n)
{
	int left = 2 * i, right = 2 * i + 1;
	int temp = 0;

	if (left > n) return;

	int small = left;

	if (right <= n) {
		if (H[right] > H[small]) small = right;
	}

	if (H[i] <= H[small]) {
		temp = H[small];
		H[small] = H[i];
		H[i] = temp;
	}

	downHeap(H, small, n);
}

void insertitem(int H[], int n, int key)
{
	H[n+1] = key;
	upHeap(H, n + 1);
	printf("0\n");

	return;
}
