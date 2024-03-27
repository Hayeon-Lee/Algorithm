#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

struct NODE {
	struct NODE *lChild, *rChild, *parent;
	int key;
}; typedef struct NODE node;

node *sibling(node *w);
node *initializeTree(node *tree);
int findElement(node *tree, int key);
void expandExternal(node *w);
node * reduceExternal(node **root, node *w);
int insertItem(node *tree, int key);
node *treeSearch(node *tree, int key);
int removeElement(node **root, node *tree, int key);
int isInternal(node *w);
int isExternal(node *w);
node *inOrderSucc(node *w);
void preOrder(node *tree);
void freeTree(node *tree);

int main() {

	node *root = (node *)malloc(sizeof(node));
	root = initializeTree(root);

	char order = 'a';
	int key = 0;

	while (order != 'q') {
		scanf("%c", &order);

		if (order == 'i') {
			scanf("%d", &key);
			int result = insertItem(root, key);
		}

		else if (order == 'd') {
			scanf("%d", &key);
			int result = removeElement(&root, root, key);

			if (result == -1) printf("X\n");
			else printf("%d\n", result);

		}

		else if (order == 's') {
			scanf("%d", &key);
			int result = findElement(root, key);

			if (result == -1) printf("X\n");
			else printf("%d\n",result);
		}

		else if (order == 'p') {
			preOrder(root);
			printf("\n");
		}

		else if(order=='q') break;
	}

	freeTree(root);
	return 0;
}

node *sibling(node *w) {
	if (w->parent == NULL) return w;

	if (w->parent->lChild == w) return w->parent->rChild;
	else return w->parent->lChild;

}

node *initializeTree(node *tree) {
	tree->lChild = NULL;
	tree->rChild = NULL;
	tree->parent = NULL;
	tree->key = 0;

	return tree;
}

int findElement(node *tree, int key) {
	node * temp = treeSearch(tree, key);

	int result = isExternal(temp);

	if (result == 1) return -1;
	else return temp->key;
}

void expandExternal(node *w) {
	node *newleft = (node *)malloc(sizeof(node));
	node *newright = (node *)malloc(sizeof(node));

	newleft->lChild = NULL;
	newleft->rChild = NULL;
	newleft->parent = w;
	newleft->key = 0;
	
	newright->lChild = NULL;
	newright->rChild = NULL;
	newright->parent = w;
	newright->key = 0;

	w->lChild = newleft;
	w->rChild = newright;
	
	return;
}

node * reduceExternal(node **root, node *z) {
	node * w = z->parent;
	node * zs = sibling(z);

	if (w->parent == NULL) {
		*root = zs;
		zs->parent = NULL;
	}

	else {
		node *g = w->parent;
		zs->parent = g;

		if (w == g->lChild) g->lChild = zs;
		else g->rChild = zs;
	}

	free(z);
	free(w);
	return zs;
}

int insertItem(node *tree, int k) {
	node *temp = treeSearch(tree, k);

	int result = isInternal(temp);

	if (result == 1) return 1;
	else {
		temp->key = k;
		expandExternal(temp);
		return 2;
	}
}

node *treeSearch(node *tree, int key) {
	if (isExternal(tree)==1) return tree;

	if (key == tree->key) return tree;
	else if (key < tree->key) return treeSearch(tree->lChild, key);
	else return treeSearch(tree->rChild, key);
}

int removeElement(node **root, node *tree, int key) {
	node *w = treeSearch(tree, key);
	
	int result = isExternal(w);
	if (result == 1) return -1;

	int e = w->key;
	node *z = w->lChild;

	result = isExternal(z);
	if (result == 2) z = w->rChild;

	result = isExternal(z);
	if (result == 1) reduceExternal(root, z);
	else {
		node *y = inOrderSucc(w);
		z = y->lChild;
		w->key = y->key;
		reduceExternal(root, z);
	}
	return e;
}

int isInternal(node *w) {
	if (w->lChild != NULL || w->rChild != NULL) return 1;
	else return 2;
}

int isExternal(node *w) {
	if (w->lChild == NULL && w->rChild == NULL) return 1;
	else return 2;
}

node *inOrderSucc(node *w) {

	w = w->rChild;
	if (isExternal(w)==1) return NULL;

	while (isInternal(w->lChild)==1) w = w->lChild;
	return w;
}

void preOrder(node *tree) {
	if (tree != NULL) {
		if(tree->key!=0) printf("%d ", tree->key);
		preOrder(tree->lChild);
		preOrder(tree->rChild);
	}
}

void freeTree(node *tree) {
	if (tree != NULL) {
		freeTree(tree->lChild);
		freeTree(tree->rChild);
		free(tree);
	}
}
