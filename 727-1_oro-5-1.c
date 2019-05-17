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

struct node1 {
	struct node *val;
	struct node1 *next;
};

struct list {
	struct node1 *head;
	struct node1 *tail;
};

void init_(struct list* l) {
	l->head = NULL;
	l->tail = l->head;
}

void clear_(struct list* l) {
	struct node1 *t = l->head;
	while (t != NULL) {
		struct node1 *tm = t;
		t = t->next;
		free(tm);
	}
	l->head = NULL;
	l->tail = NULL;
}

int isEmpty(struct list* l) {
	if (l->head != NULL) {
		return 1;
	}
	else
		return 0;
}


int push_back(struct list* l, struct node* value) {
	struct node1* t = (struct node1*)malloc(sizeof(struct node1));
	t->val = value;
	t->next = NULL;
	if (l->tail == NULL) {
		l->tail = t;
		l->head = l->tail;
	}
	else {
		l->tail->next = t;
		l->tail = t;
	}
	t = NULL;
	return 0;
}



void print_(struct list* l) {
	struct node1* t = l->head;
	while (t != NULL) {
		struct node* t1 = t->val;
		int u = t1->value;
		if (t->next != NULL) {
			printf("%d%c", u, ' ');
		}
		else {
			printf("%d\n", u);
		}
		t = t->next;
	}
	t = NULL;
}

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

int remove_(struct list* l, struct node* value) {
	struct node1* tmp = l->head;
	if (l->head->next != NULL) {
		l->head = l->head->next;
	}
	else {
		l->head = NULL;
		l->tail = l->head;
	}
	free(tmp);
}


struct node* popout(struct list* l) {
	if (l->head != NULL) {
		struct node* u = l->head->val;
		remove_(l, l->head);
		return u;
	}
	return NULL;
}


void glub(struct node* n) {
	struct list* l = (struct list*)malloc(sizeof(struct list));
	struct list* l1 = (struct list*)malloc(sizeof(struct list));
	init(l);
	init(l1);
	push_back(l, n);
	while (isEmpty(l)) {
		struct node* tmp = popout(l);
		push_back(l1, tmp);
		if (tmp->left != NULL) {
			push_back(l, tmp->left);
		}
		if (tmp->right != NULL) {
			push_back(l, tmp->right);
		}
		
	}
	print_(l1);
	clear_(l);
	free(l);
	clear_(l1);
	free(l1);
}

int main() {
	struct tree* q = (struct tree*)malloc(sizeof(struct tree));
	init(q);
	int m;
	for (int i = 0; i < 7; i++) {
		scanf("%d", &m);
		insert(q, m);
	}
	glub(q->root);

	free(q);
	return 0;
}
