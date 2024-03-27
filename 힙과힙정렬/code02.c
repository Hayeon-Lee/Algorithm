#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void buildHeap(int H[], int n);
void downHeap(int H[], int i, int n);
void printHeap(int H[], int n);

int main()
{
	int n = 0, *H = NULL;

	scanf("%d", &n);
	H = (int *)malloc(sizeof(int)*(n+1));
	H[0] = 0;

	for (int i = 1; i <= n; i++) scanf(" %d", &H[i]);
	buildHeap(H, n);
	printHeap(H, n);

	free(H);
	return 0;
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

void buildHeap(int H[], int n)
{
	for (int i = n / 2; i >= 1; i--) downHeap(H, i, n);
	return;
}

void printHeap(int H[], int n)
{
	for (int i = 1; i <= n; i++) printf(" %d", H[i]);
	printf("\n");
}

void removeMax(int H[], int n)
{
	printf("%d\n", H[1]);
	H[1] = H[n];
	downHeap(H, 1, n - 1);
}

void printHeap(int H[], int n)
{
	for (int i = 1; i <= n; i++) printf(" %d", H[i]);
	printf("\n");
}
