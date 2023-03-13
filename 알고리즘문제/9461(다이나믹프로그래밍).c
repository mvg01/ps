#include <stdio.h>
#define MAX(a,b)a>b?a:b

int main(void)
{
	int t, n;
	long long dp[101];  //int형을 넘어서는 값이 나오니 주의
	scanf("%d", &t); 
	dp[0] = 1; dp[1] = 1;  //초기값 대충 넣어주고 규칙을 찾아보자
	dp[2] = 1; dp[3] = 2;
	dp[4] = 2; dp[5] = 3;
	for (int i = 6; i < 101; i++)
		dp[i] = dp[i - 3] + dp[i - 2];  //라는 점화식이 성립된다.

	while (t--) {
		scanf("%d", &n);
		printf("%lld\n", dp[n-1]);  
	}
}