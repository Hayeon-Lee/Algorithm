#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct Node {
	int key;
	struct Node *next;
}; typedef struct Node node;

void init(node *T, int M);
int modulo(int k, int M);
void insert(node *T, int k, int M);
int search(node *T, int k, int M);
void dele(node *T, int k, int M);
void print(node *T, int M);
void free_f(node *T, int M);

int main() {
	int M = 0, k = 0;

	scanf("%d", &M);
	node *T = (node *)malloc(sizeof(node)*M);
	init(T, M); //초기화

	char order = 'a';

	while (order != 'e') {
		scanf("%c", &order);

		if (order == 'i') {
			scanf("%d", &k);
			insert(T, k, M);
		}

		if (order == 's') {
			scanf("%d", &k);
			search(T, k, M);
		}

		if (order == 'd') {
			scanf("%d", &k);
			dele(T, k, M);
		}

		if (order == 'p') print(T, M);

		if (order == 'e') break;
	}

	free_f(T, M);
	return 0;
}

void init(node *T, int M) {
	for (int i = 0; i < M; i++) T[i].next = NULL;
	return;
}

int modulo(int k, int M) {
	return (k%M);
}

void insert(node *T, int k, int M) {
	int mod = modulo(k, M);

	node *newnode = (node *)malloc(sizeof(node));
	newnode->key = k;

	node *temp = T[mod].next;
	T[mod].next = newnode;
	newnode->next = temp;

	return;
}

int search(node *T, int k, int M) {
	int mod = modulo(k, M), i = 1;
	node *temp = T[mod].next;

	while (temp != NULL) {
		if (temp->key == k) {
			printf("%d\n", i);
			return i; //순서 반환
		}
		else {
			temp = temp->next;
			i++;
		}
	}

	printf("0\n");
	return 0; //없음
}

void dele(node *T, int k, int M) {
	int re = search(T, k, M);

	if (re == 0) return;

	int mod = modulo(k, M);
	node *temp = T[mod].next;
	node *index = NULL;

	if (temp->key == k) {
		T[mod].next = temp->next;
		free(temp);
		return;
	}

	for (int i = 0; i < re - 1; i++) {
		if (temp->next->key == k) index = temp;
		temp = temp->next;
	}
	
	index->next = temp->next;
	free(temp);
	return;
}

void print(node *T, int M) {
	node *temp = T[0].next;

	for (int i = 0; i < M; i++) {
		temp = T[i].next;
		while (temp != NULL) {
			printf(" %d", temp->key);
			temp = temp->next;
		}
	}
	printf("\n");
	return;
}

void free_f(node *T, int M) {
	node *temp = T[0].next;
	node *box = NULL;

	for (int i = 0; i < M; i++) {
		temp = T[i].next;

		while (temp != NULL) {
			box = temp->next;
			free(temp);
			temp = box;
		}
	}

	free(T);
	return;
}
