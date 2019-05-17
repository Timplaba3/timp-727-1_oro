#include<stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node *left;
	struct node *right;
	struct node *prev;
};

struct tree {
	struct node *root;
	int count;
};

void init(struct tree* t) {
	t->root = NULL;
	t->count = 0;
}

void clear(struct tree* t) {
	while (t->root->right != NULL || t->root->left != NULL) {
		remov(t, t->root->value);
	}
	struct node* tmp = t->root;
	free(tmp);
	t->root = NULL;
	t->count = 0;
}


int insert(struct tree* t, int value) {
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	if (tmp == NULL) {
		return 2;
	}
	tmp->value = value;
	tmp->left = NULL;
	tmp->right = NULL;
	tmp->prev = NULL;
	struct node* t2 = t->root;
	if (t2 == NULL) {
		t2 = tmp;
		t->root = t2;
		t->count++;
		return 0;
	}
	for (;;) {
		if (t2->value == value) {
			return 1;
		}
		struct node* t3;
		if (t2->value > value)
		{
			if (t2->left == NULL) {
				t2->left = tmp;
				t2->left->prev = t2;
				tmp = NULL;
				t->count++;
				return 0;
			}
			else {
				t3 = t2;
				t2 = t2->left;
			}
		}
		else
		{
			if (t2->right == NULL) {
				t2->right = tmp;
				t2->right->prev = t2;
				tmp = NULL;
				t->count++;
				return 0;
			}
			else {
				t2 = t2->right;
			}
		}
	}
}

int removeMin(struct node* n) {
	while (n->left != NULL) {
		n = n->left;
	}
	int t = n->value;
	if (n->right != NULL && n->prev != NULL) {
		n->prev->right = n->right;
		n->right->prev = n->prev;
	}
	free(n);
	return t;
}

int remov(struct tree* t, int value) {
	struct node* t2 = t->root;
	if (t2 == NULL) {
		return 1;
	}
	while (t2 != NULL) {
		if (t2->value == value) {
			if (t2->left != NULL && t2->right != NULL) {
				t2->value = removeMin(t2->right);
				t->count--;
			}
			else if (t2->left != NULL) {
				struct node* tmp = t2;
				if (tmp == t->root) {
					t->root = t2->left;
				}
				t2->left->prev = t2->prev;
				t2 = t2->left;
				free(tmp);
				tmp = NULL;
				t->count--;
			}
			else if (t2->right != NULL) {
				struct node* tmp = t2;
				if (t2->prev == NULL) {
					t->root->right->prev = NULL;
					t->root = t2->right;
				}
				else {
					t2->right->prev = t2->prev;
					t2 = t2->right;
				}
				free(tmp);
				tmp = NULL;
				t->count--;
			}
			else {
				if (t2->prev->left == t2) {
					struct node* tmp = t2;
					t2->prev->left = NULL;
					free(tmp);
					tmp = NULL;
					t->count--;
				}
				else {
					struct node* tmp = t2;
					t2->prev->right = NULL;
					free(tmp);
					tmp = NULL;
					t->count--;
				}
			}
			return 0;
		}
		if (t2->value > value) {
			t2 = t2->left;
		}
		else {
			t2 = t2->right;
		}
	}
	return 1;
}

void glub_rec(struct node* n) {
	if (n == NULL) return;
	glub_rec(n->left);
	glub_rec(n->right);
	if(n->prev!=NULL)
		printf("%d ", n->value);
	else
		printf("%d\n", n->value);
}


int main() {
	struct tree* q = (struct tree*)malloc(sizeof(struct tree));
	init(q);
	int m;
	for (int i = 0; i < 7; i++) {
		scanf("%d", &m);
		insert(q, m);
	}
	glub_rec(q->root);
	free(q);
	return 0;
}
