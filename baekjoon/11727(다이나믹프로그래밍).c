//11726과 비슷한 방식으로 생각하면 되는 문제. n=4 까지 넣어보니까 14번째줄의 점화식이 나왔다.

#include <stdio.h>

int main(void)
{
	int n;
	int dp[1001];
	scanf("%d", &n);
	dp[1] = 1;
	dp[2] = 3;
	dp[3] = 5;
	for (int i = 4; i <= n; i++)
		dp[i] = ((dp[i - 2] * 2) + dp[i - 1]) % 10007;
	printf("%d", dp[n]);
}