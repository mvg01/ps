#include <stdio.h>
#include <stdlib.h>
long long v[100001];
long long sum[100001];

int main()
{	
	int n, m;
	scanf("%d %d", &n, &m);

	for (int i = 1; i <= n; i++) {
		scanf("%lld", &v[i]);
	}
	
	//첫날부터 m일동안 일
	for (int i = 1; i <= m; i++)
		sum[m] += v[i];

	int idx = 1;
	for (int i = m + 1; i <= n; i++) {
		sum[i] = sum[i - 1] + v[i] - v[idx++];
	}

	long long max = 0;
	for (int i = m; i <= n; i++) {
		//printf("%lld ", sum[i]);
		if (max < sum[i])
			max = sum[i];
	}
	printf("%lld", max);
}