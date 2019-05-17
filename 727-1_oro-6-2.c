#include<stdio.h>
#include<stdlib.h>

int shell(int *arr, int n) {
	int count = 0;
	for (int d = n / 2; d > 0; d /= 2) {
		for (int i = d; i < n; i++) {
			int t = arr[i];
			int j=i;
			count++;
				while ((j > 0) && (arr[j - d] > t)) {
					arr[j] = arr[j - d];
					j = j - d;
					count++;
				}
			arr[j] = t;
		}
	}
	return count;
}

int main() {
	int n;
	scanf("%d", &n);
	int *q = (int*)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++) {
		scanf("%d", &q[i]);
	}

	shell(q, n);

	for (int i = 0; i < n-1;i++) {
		printf("%d ", q[i]);
	}
	printf("%d\n", q[n-1]);
	
	return 0;
}
