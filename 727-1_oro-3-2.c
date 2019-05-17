#include<stdio.h>
#include<stdlib.h>

struct node {
	int value;
	struct node *next;
	struct node *prev;
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
			return t;
		}
		else {
			t = t->next;
		}
	}
	t = NULL;
	return NULL;
}

int push_back(struct list* l, int value) {
	struct node* t= (struct node*)malloc(sizeof(struct node));
	t->value = value;
	t->next = NULL;
	t->prev = NULL;
	if (l->tail->value == NULL) {
		l->tail = t;
		l->head = l->tail;
	}
	else {
		t->prev = l->tail;
		l->tail->next = t;
		l->tail = t;
	}
	t = NULL;
	return 0;
}

int push_front(struct list* l, int value) {
	struct node* t = (struct node*)malloc(sizeof(struct node));
	t->value = value;
	t->next = NULL;
	t->prev = NULL;
	if (l->head->value == NULL) {
		l->head = t;
		l->tail = l->head;
	}
	else {
		t->next = l->head;
		l->head->prev = t;
		l->head = t;
	}
	t = NULL;
	return 0;
}

int insertAfter(struct list* l, int j, int value) {
	
	struct node* t = l->head;
	for (int i = 0; i < j - 1; i++) {
		if (t->next != NULL) {
			t = t->next;
		}
		else {
			return 1;
		}
	}
	struct node* tmp = (struct node*)malloc(sizeof(struct node));
	tmp->value = value;
	tmp->prev = t;
	if (t->next != NULL) {
		tmp->next = t->next;
	}
	else {
		tmp->next = NULL;
		tmp->prev = l->tail;
		l->tail = tmp;
		return 0;
	}
	t->next->prev = tmp;
	t->next = tmp;
	tmp = NULL;
	return 0;
}

int insertBefore(struct list* l, int j, int value) {
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
	tmp->next = t;
	if (t->prev != NULL) {
		tmp->prev = t->prev;
	}
	else {
		tmp->prev = NULL;
		tmp->next = l->head;
		l->head = tmp;
		return 0;
	}
	t->prev->next = tmp;
	t->prev = tmp;
	tmp = NULL;
	return 0;
}

int removeFirst(struct list* l, int value) {
	struct node* t = l->head;
	struct node* tmp;
	if (t->value == value) {
		tmp = l->head;
		l->head = l->head->next;
		l->head->prev = NULL;
		t = NULL;
		free(tmp);
		return 0;
	}
	else
		while (t != NULL && t->next != NULL) {
			if (t->next->value == value && t->next->next != NULL) {
					tmp = t->next;
					t->next = t->next->next;
					t->next->prev = t;
					t = NULL;
					tmp = NULL;
					return 0;
			}
			else
			{
				t = t->next;
			}
		}
	if (t->next == NULL && t->value == value) {
		tmp = l->tail;
		l->tail = l->tail->prev;
		l->tail->next = NULL;
		t = NULL;
		free(tmp);
		tmp = NULL;
		return 0;
	}
	t = NULL;
	return 1;
}

int removeLast(struct list* l, int value) {
	struct node* t = l->tail;
	struct node* tmp;
	if (t->value == value) {
		tmp = l->tail;
		l->tail = l->tail->prev;
		l->tail->next = NULL;
		t = NULL;
		free(tmp);
		return 0;
	}
	else
		while (t != NULL && t->prev != NULL) {
			if (t->prev->value == value && t->prev->prev != NULL) {
				tmp = t->prev;
				t->prev = t->prev->prev;
				t->prev->next = t;
				t = NULL;
				tmp = NULL;
				return 0;
			}
			else
			{
				t = t->prev;
			}
		}
	if (t->prev == NULL && t->value == value) {
		tmp = t;
		l->head = t->next;
		l->head->prev = NULL;
		free(tmp);
		t = NULL;
		tmp = NULL;
		return 0;
	}
	t = NULL;
	return 1;
}

void print(struct list* l) {
	struct node* t = l->head;
	while (t != NULL) {
		if (t->next != NULL) {
			printf("%d%c", t->value, ' ');
		}
		else {
			printf("%d\n", t->value);
			break;
		}
		t = t->next;
	}
	t = NULL;
}

void print_inverse(struct list* l) {
	struct node* t = l->tail;
	while (t != NULL) {
		if (t->prev != NULL) {
			printf("%d%c", t->value, ' ');
		}
		else {
			printf("%d\n", t->value);
			break;
		}
		t = t->prev;
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
	print_inverse(q);
	scanf("%d", &m);
	push_front(q, m);
	print(q);
	int j;
	scanf("%d%d", &j, &m);
	insertAfter(q, j, m);
	print_inverse(q);
	scanf("%d%d", &j, &m);
	insertBefore(q, j, m);
	print(q);
	scanf("%d", &m);
	removeFirst(q, m);
	print_inverse(q);
	scanf("%d", &m);
	removeLast(q, m);
	print(q);
	clear(q);
	q = NULL;
	return 0;
}
