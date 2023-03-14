//주어진 예시들을 보고 n=4 정도까지만 직접 계산해봤다. 그 결과 피보나치 수열임을 알게 되었다.

#include <stdio.h>

int main(void)
{
	int n, i, j;
	scanf("%d", &n);
	int dp[1001];
	dp[0] = 1;
	dp[1] = 2;
	dp[2] = 3;
	for (i = 3; i <= n; i++)
		dp[i] = (dp[i - 1] + dp[i - 2]) % 10007;

	printf("%d", dp[n - 1]);
}