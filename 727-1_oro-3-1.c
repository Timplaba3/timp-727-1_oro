#include<stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node *next;
};

struct list {
	struct node *head;
	struct node *tail;
};

void init(struct list* l) {
	l->head = (struct node*)malloc(sizeof(struct node));
	l->head->next = NULL;
	l->head->value = NULL;
	l->tail = l->head;
}

void clear(struct list* l) {
	free(l);
	l = NULL;
}

int isEmpty(struct list* l) {
	if (l->head->next != NULL) {
		return 1;
	}
	else
		return 0;
}

struct node* find(struct list* l, int value) {
	struct node* t = l->head;
	while (t != NULL) {
		if (t->value == value) {
			return 1;
		}
		else {
			t = t->next;
		}
	}
	t = NULL;
	return 0;
}

int push_back(struct list* l, int value) {
	struct node* t = (struct node*)malloc(sizeof(struct node));
	t->value = value;
	t->next = NULL;
	if (l->tail->value == NULL) {
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

int push_front(struct list* l, int value) {
	struct node* t = (struct node*)malloc(sizeof(struct node));
	t->value = value;
	if (l->head->value==NULL) {
		l->head = t;
		l->tail = l->head;
	}else{
		t->next = l->head;
		l->head = t;
	}
	t = NULL;
	return 0;
}

int insertAfter(struct list* l, int j, int value) {
	struct node* t = l->head;
		for (int i = 0; i < j - 1; i++) {
			if (t != NULL) {
				t = t->next;
			}
			else {
				return 1;
			}
		}
		struct node* tmp = (struct node*)malloc(sizeof(struct node));
		tmp->value = value;
		if (t != NULL) {
			tmp->next = t->next;
		}
		else {
			tmp->next = NULL;
			l->tail = tmp;
		}
		t->next = tmp;
		tmp = NULL;
		return 0;
}

int remov(struct list* l, int value) {
	struct node* t = l->head;
	struct node* tmp;
	if (t->value == value) {
		l->head = t->next;
		t = NULL;
		return 0;
	}
	else
		while (t != NULL && t->next != NULL) {
			if (t->next->value == value && t->next->next != NULL) {
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
	if (t->next=NULL && t->value==value) {
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

void print(struct list* l) {
	struct node* t=l->head;
	while (t!=NULL) {
		if (t->next != NULL) {
			printf("%d%c", t->value, ' ');
		}
		else {
			printf("%d\n", t->value);
		}
		t = t->next;
	}
	t = NULL;
}



int main(void) {
	int n, m;
	struct list* q = (struct list*)malloc(sizeof(struct list));
	init(q);

	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &m);
		push_back(q, m);
	}

	print(q);
	for (int i = 0; i < 3; i++) {
		scanf("%d", &m);
		if (find(q, m) == NULL) {
			printf("%d", 0);
		}
		else {
			printf("%d", 1);
		}
	}
	printf("\n");

	scanf("%d", &m);
	push_back(q, m);
	print(q);

	scanf("%d", &m);
	push_front(q, m);
	print(q);

	int j;
	scanf("%d%d", &j, &m);
	insertAfter(q, j, m);
	print(q);

	scanf("%d", &m);
	remov(q, m);
	print(q);

	clear(q);
	return 0;
}
