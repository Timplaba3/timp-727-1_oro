#include<stdio.h>
#include<stdlib.h>

int sort(int *arr, int n) {
	return quicksort(arr,0,n-1);
}

int quicksort(int *a, int left, int right) {
	int i = left;
	int j = right;
	int count = 0;
	int m = (i + j) / 2;
	int op = a[m];
	while (j>=i) {
		while (a[i]<op) {
			i++;
			count++;
		}
		while (a[j] > op) {
			j--;
			count++;
		}
		if (i<=j) {
			int t = a[i];
			a[i] = a[j];
			a[j] = t;
			count++;
			i++;
			j--;
		}
		if (left < j) {
			count+=quicksort(a,left,j);
		}
		if (i < right) {
			count+=quicksort(a,i,right);
		}
		
	}
	return count;
}

int main() {
	int n;
	scanf("%d", &n);
	int *q = (int*)malloc(n * sizeof(int*));
	for (int i = 0; i < n;i++) {
		scanf("%d", &q[i]);
	}

	sort(q, n);

	for (int i = 0; i < n - 1;i++) {
		printf("%d ", q[i]);
	}
	printf("%d\n", q[n - 1]);
	free(q);
	q = NULL;
	return 0;
}
