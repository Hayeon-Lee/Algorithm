#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct NODE {
	int elem;
	struct NODE *next;
}; typedef struct NODE node;

struct List1and2 {
	node *list1;
	node *list2;
}; typedef struct List1and2 l1l2;

node *getnode(int value);
void mergeSort(node **list, int N);
node *merge(node *list1, node *list2);
l1l2 mg_partition(node *list, int k);
void print(node *list);
void free_f(node *list);

int main() {
	node *list_head=NULL, *temp=NULL;
	int N, value;
	
	list_head = (node *)malloc(sizeof(node));
	list_head->next = NULL;

	scanf("%d", &N);
	temp = list_head;

	for (int i = 0; i < N; i++) {
		scanf("%d", &value);
		temp->next = getnode(value);
		temp = temp->next;
	}

	mergeSort(&list_head->next, N);
	print(list_head->next);
	free_f(list_head);
}

node *getnode(int value) {
	node *newnode = (node *)malloc(sizeof(node));

	newnode->elem = value;
	newnode->next = NULL;

	return newnode;
}

void mergeSort(node **list, int N) {
	node *L1 = NULL, *L2 = NULL;
	l1l2 box;

	if (N > 1 && *list != NULL) {
		box = mg_partition(*list, N / 2);
		L1 = box.list1;
		L2 = box.list2;

		mergeSort(&L1, N / 2);
		mergeSort(&L2, (int)((N / 2.0) + 0.5));

		*list = merge(L1, L2);
	}
}
node *merge(node *list1, node *list2) {
	node *sort_list = NULL;

	if (list1 == NULL) return list2;
	else if (list2 == NULL) return list1;

	if (list1->elem < list2->elem) {
		sort_list = list1;
		sort_list->next = merge(list1->next, list2);
	}
	else {
		sort_list = list2;
		sort_list->next = merge(list1, list2->next);
	}
	return sort_list;
}
l1l2 mg_partition(node *list, int k) {
	node *temp=list, *L1=list, *L2;
	l1l2 result;

	for (int i = 0; i < k - 1; i++) temp = temp->next;
	L2 = temp->next;
	temp->next = NULL;

	result.list1 = L1;
	result.list2 = L2;

	return result;
}
void print(node *list) {
	node *temp = list;

	while (temp != NULL) {
		printf("%d ", temp->elem);
		temp = temp->next;
	}
	printf("\n");

	return;
}

void free_f(node *list) {
	node *temp = list;

	while (temp != NULL) {
		temp = list->next;
		free(list);
		list = temp;
	}

	return;
}
