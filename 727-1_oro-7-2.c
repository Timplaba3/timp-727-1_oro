#include<stdio.h>
#include<stdlib.h>

int sort(int *arr, int n) {
	int count = 0;
	while (n>1) {
		for (int i = n / 2; i >= 0; i--) {
			if (2 * i + 2 < n) {
				if (arr[2 * i + 2] > arr[i]) {
					int t = arr[2 * i + 2];
					arr[2 * i + 2] = arr[i];
					arr[i] = t;
					i = 2 * i + 3;
					count++;
				}
				count++;
			}
			if (2 * i + 1 < n) {
				if (arr[2 * i + 1] > arr[i]) {
					int t = arr[2 * i + 1];
					arr[2 * i + 1] = arr[i];
					arr[i] = t;
					i = 2 * i + 2;
					count++;
				}
				count++;
			}	
		}
		count++;
		int t = arr[0];
		arr[0] = arr[n-1];
		arr[n-1] = t;
		n--;
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
	return 0;
}
