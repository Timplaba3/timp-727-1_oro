#include<stdio.h>
#include<stdlib.h>

int rasch(int *arr, int n) {
	int count = 0;
	for (int d = n / 1.247; d >= 1; d/= 1.247) {
		for (int i = 0; i < n - d; i++) {
			for (int j = 0; j < n - d - i; j++) {
				if (arr[j] > arr[j + d]) {
					int t = arr[j];
					arr[j] = arr[j + d];
					arr[j + d] = t;
					count++;
				}
				count++;
			}
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

	rasch(q, n);

	for (int i = 0; i < n-1;i++) {
		printf("%d ", q[i]);
	}
	printf("%d\n", q[n - 1]);
	return 0;
}

