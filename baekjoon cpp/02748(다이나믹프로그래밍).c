#include <stdio.h>

long long dp[91];
void DP(int n) {
	dp[0] = 0;  //초기값 지정
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= 90; i++)
		dp[i] = dp[i - 1] + dp[i - 2];
	printf("%lld", dp[n]);
}

int main(void)
{
	int n;
	scanf("%d", &n);
	DP(n);
}