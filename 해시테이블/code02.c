#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void init(int *T, int M);
int modulo(int key, int M);
void insert(int *T, int key, int M);
int getNextBucket(int mod, int i, int M);
void search(int *T, int key, int M);

int main() {
	int M = 0, n = 0, key = 0;
	scanf("%d %d", &M, &n);

	int *T = (int *)malloc(sizeof(int)*M);
	init(T, M);

	char order = 'a';

	while (order != 'e') {
		scanf("%c", &order);

		if (order == 'i') {
			scanf("%d", &key);
			insert(T, key, M);
		}

		if (order == 's') {
			scanf("%d", &key);
			search(T, key, M);
		}

		if (order == 'e') break;
	}

	free(T);
	return 0;
}

void init(int *T, int M) {
	for (int i = 0; i < M; i++) T[i] = 0;
	return;
}

int modulo(int key, int M) {
	return (key%M);
}

void insert(int *T, int key, int M) {
	int mod = modulo(key, M), c = 0, i = 0, b = 0;

	if (T[mod] == 0) {
		T[mod] = key;
		printf("%d\n", mod);
		return;
	}

	else {
		while (i<M) {
			b = getNextBucket(mod, i, M);
			if (T[b] == 0) {
				T[b] = key;
				break;
			}
			else {
				i += 1;
				c++;
			}
		}

		for (int i = 0; i < c; i++) printf("C");
		printf("%d\n", b);
	}

	return;
}

int getNextBucket(int mod, int i, int M) {
	return ((mod + i) % M);
}

void search(int *T, int key, int M) {
	int mod = modulo(key, M);
	int i = 0, index = 0;

	while (i < M) {
		index = getNextBucket(mod, i, M);

		if (T[index] == 0) {
			printf("-1\n");
			return;
		}
		else if (T[index] == key) {
			printf("%d %d\n", index, key);
			return;
		}
		else i++;
	}

	printf("-1\n");
	return;
}
