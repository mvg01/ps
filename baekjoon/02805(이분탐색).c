#include <stdio.h>
#include <stdlib.h>
int tree[1000001];
int static compare(int* a, int* b) 
{
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}

int main()
{
	int n, m, i, max, x = 0;
	long long start, end, sum, cut;
	scanf("%d %d", &n, &m);
	for (i = 0; i < n; i++)
		scanf("%d", &tree[i]);
	qsort(tree, n, 4, compare);
	max = tree[n - 1];

	start = 1, end = max; 
	while (start<=end) {
		sum = 0;
		cut = (start + end) / 2;
		for (i = 0; i < n; i++) {
			if (tree[i] - cut > 0)
				sum += tree[i] - cut;
		}

		if (sum >= m) {
			if (x < cut)
				x = cut;

			start = cut + 1;
		}

		else
			end = cut - 1;
	}
	printf("%d", x);
}