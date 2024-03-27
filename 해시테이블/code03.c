#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void init(int *T, int M);
int hash_1(int key, int M);
int hash_2(int key, int q);
int getNextBucket(int v, int i, int M, int h);
void insert(int *T, int key, int M, int q);
void search(int *T, int key, int M, int q);
void print(int *T, int M);

int main() {
	int M = 0, n = 0, q = 0, key = 0;
	scanf("%d %d %d", &M, &n, &q);

	int *T = (int *)malloc(sizeof(int)*M);
	init(T, M);

	char order = 'a';

	while (order != 'e') {
		scanf("%c", &order);

		if (order == 'i') {
			scanf("%d", &key);
			insert(T, key, M, q);
		}

		if (order == 's') {
			scanf("%d", &key);
			search(T, key, M, q);
		}

		if (order == 'p') print(T, M);

		if (order == 'e') {
			print(T, M);
			break;
		}
	}

	free(T);
	return 0;
}

void init(int *T, int M) {
	for (int i = 0; i < M; i++) T[i] = 0;
	return;
}

int hash_1(int key, int M) {
	return key % M;
}

int hash_2(int key, int q) {
	return (q - (key%q));
}

int getNextBucket(int v, int i, int M, int h) {
	return ((v + i * h) % M);
}

void insert(int *T, int key, int M, int q) {
	int mod = hash_1(key, M);
	int b = 0, c = 0, i = 0;

	if (T[mod] == 0) {
		T[mod] = key;
		printf("%d\n", mod);
		return;
	}

	else {
		while (i<M) {
			b = getNextBucket(mod, i, M, hash_2(key, q));
			if (T[b] == 0) {
				T[b] = key;
				break;
			}
			else {
				c++;
				i++;
			}
		}
		for (int i = 0; i < c; i++) printf("C");
		printf("%d\n", b);
	}

	return;
}

void search(int *T, int key, int M, int q) {
	int v = hash_1(key, M);
	int i = 0, b = 0;

	while (i < M) {
		b = getNextBucket(v, i, M, hash_2(key, q));
		if (T[b] == 0) {
			printf("-1\n");
			return;
		}
		else if (T[b] == key) {
			printf("%d %d\n", b, key);
			return;
		}
		else i++;
	}

	printf("-1\n");
	return;
}

void print(int *T, int M) {
	for (int i = 0; i < M; i++) printf(" %d", T[i]);
	printf("\n");
}
