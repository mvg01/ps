//점화식으로 쉽게 도출해 낼 수 있었다.
#include <stdio.h>
long long dp[81];
int main()
{
	int n;
	scanf("%d", &n);
	dp[1] = 4; dp[2] = 6;
	dp[3] = 10; dp[4] = 16;
	for (int i = 5; i <= n; i++)
		dp[i] = dp[i - 2] + dp[i - 1];

	printf("%lld", dp[n]);
}