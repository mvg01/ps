#include <stdio.h>
#include <stdlib.h>

long long a[100001];
long long sum[100001];
int main()
{	
	int n;
	long long res = 0;
	scanf("%d", &n);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	for (int i = 1; i <= n; i++) {
		res += a[i] * (sum[n] - sum[i]);
	}
	printf("%lld", res);
}