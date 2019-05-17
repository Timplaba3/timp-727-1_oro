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
	if (l->head!= NULL) {
		return 1;
	}
	else
		return 0;
}


int push_back(struct list* l, struct node* value) {
	struct node1* t = (struct node1_*)malloc(sizeof(struct node1));
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

int remove_(struct list* l, struct node* value) {
	struct node1* t = l->head;
	struct node1* tmp;
	if (t->val == value) {
		l->head = t->next;
		t = NULL;
		return 0;
	}
	else
		while (t != NULL && t->next != NULL) {
			if (t->next->val == value && t->next->next != NULL) {
				tmp = t->next;
				t->next = t->next->next;
				free(tmp);
				t = NULL;
				tmp = NULL;
				return 0;
			}
			else
			{
				t = t->next;
			}
		}
	if (t->next->next = NULL && t->val == value) {
		tmp = t->next;
		t->next = NULL;
		l->tail = t;
		free(tmp);
		t = NULL;
		tmp = NULL;
		return 0;
	}
	t = NULL;
	return 1;
}

void print_(struct list* l) {
	struct node1* t = l->head;
	while (t != NULL) {
		if (t->val->value != 25565) {
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
		else {
			if (t->next != NULL) {
				printf("%c ", '_');
			}
			else {
				printf("%c\n", '_');
			}
			t = t->next;
		}
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

int find(struct tree* t, int value, struct node** n) {
	struct node* tmp = t->root;
	for (;;) {
		if (tmp != NULL) {
			if(tmp->value==value){
				if (n != NULL) {
					*n = tmp;
				}
				tmp = NULL;
				return 0;
			}
			else
			if (tmp->value > value)
			{
				tmp = tmp->left;
			}
			else
			{
				tmp = tmp->right;
			}
		}
		else {
			return 1;
		}
	}

}

int insert(struct tree* t, int value) {
	struct node* tmp= (struct node*)malloc(sizeof(struct node));
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
			if (t2->left != NULL && t2->right!= NULL) {
				t2->value = removeMin(t2->right);
				t->count--;
			}
			else if (t2->left!=NULL) {
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
				}else{
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
	int t= n->value;
	if(n->right!=NULL && n->prev!=NULL){
		n->prev->right = n->right;
		n->right->prev = n->prev;
	}
	free(n);
	return t;
}

int rotateRight(struct node* n) {
	if (n->left == NULL) {
		return 1;
	}
	struct node* tmp = n->left;
	if (n->prev != NULL) {
		if (n->prev->left == n) {
			n->prev->left = tmp;
		}
		else {
			n->prev->right = tmp;
		}
	}
	tmp->prev = n->prev;
	n->prev = tmp;
	struct node* t1 = tmp->right;
	tmp->right = n;
	n->left = t1;
	n = tmp;
	return 0;
}

int rotateLeft(struct node* n) {
	if (n->right == NULL) {
		return 1;
	}
	struct node* tmp = n->right;
	if (n->prev != NULL) {
		if (n->prev->left == n) {
			n->prev->left = tmp;
		}
		else {
			n->prev->right = tmp;
		}
	}
	tmp->prev = n->prev;
	n->prev = tmp;
	struct node* t1 = tmp->left;
	tmp->left = n;
	n->right = t1;
	n = tmp;
	return 0;
}

void print(struct node* n) {
	struct list* l1=(struct list*)malloc(sizeof(struct list));
	struct list* l2 = (struct list*)malloc(sizeof(struct list));
	init_(l1);
	init_(l2);
	push_back(l1,n);
	struct node* proch= (struct node*)malloc(sizeof(struct node));
	proch->value = 25565;
	proch->left = NULL;
	proch->right = NULL;
	int flag = 1;
	for (;;) {
		if (flag) {
			print_(l1);
			flag = 0;
		}
		else {
			break;
		}
		while (isEmpty(l1)) {
			struct node* tmp = l1->head->val;
			
			remove_(l1, tmp);
			if (tmp->right!=NULL || tmp->left!=NULL) {
				flag=1;
			}
			
			if (tmp->left != NULL) {
				push_back(l2, tmp->left);
			}
			else {
				push_back(l2, proch);
			}
			if (tmp->right != NULL) {
				push_back(l2, tmp->right);
			}
			else {
				push_back(l2, proch);
			}			
		}
		struct list* l = l1;
		l1 = l2;
		l2 = l;
		l2->head = NULL;
		l2->tail = NULL;
		l = NULL;
	}
	clear_(l1);
	free(l1);
	clear_(l2);
	free(l2);
}

void printTree(struct tree* t) {
	if (t->root != NULL) {
		print(t->root);
	}
	else {
		printf("-\n");
	}
}



int main() {
	struct tree* q = (struct tree*)malloc(sizeof(struct tree));
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	init(q);
	int m;
	for (int i = 0; i < 4; i++) {
		scanf("%d", &m);
		insert(q, m);
	}
	printTree(q);

	for (int i = 0; i < 3; i++) {
		scanf("%d", &m);
		insert(q, m);
	}
	printTree(q);

	for (int i = 0; i < 2; i++) {
		scanf("%d", &m);
		if (!find(q, m, &tmp)) {
			if (tmp->prev != NULL) {
				printf("%d%c", tmp->prev->value, ' ');
			}
			else {
				printf("%c%c", '_', ' ');
			}
			if (tmp->left != NULL) {
				printf("%d%c", tmp->left->value, ' ');
			}
			else
				printf("%c%c", '_', ' ');
			if (tmp->right != NULL) {
				printf("%d\n", tmp->right->value);
			}
			else
				printf("%c\n", '_');
		}
		else {
			printf("-\n");
		}
	}

	scanf("%d", &m);
	remov(q, m);
	printTree(q);

	for (;;)
	{
		tmp = q->root->right;
		if (rotateLeft(q->root)) break;
		q->root = tmp;
	}
	printTree(q);

	for (;;)
	{
		tmp = q->root->left;
		if (rotateRight(q->root)) break;
		q->root = tmp;
	}
	printTree(q);

	printf("%d\n", q->count);
	clear(q);
	printTree(q);

	free(q);
	return 0;
}
