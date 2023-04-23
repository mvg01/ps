#include <stdio.h>
#define MAX(a,b) (a>b?a:b)
int main()
{
	int n, i, a[301];
	scanf("%d", &n);
	for (i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	int dp[301];
	dp[0] = 0;
	dp[1] = a[1];
	dp[2] = a[1] + a[2];
	for (i = 3; i <= n; i++)
		dp[i] = a[i] + MAX(dp[i - 2], dp[i - 3] + a[i - 1]);

	printf("%d", dp[n]);
}