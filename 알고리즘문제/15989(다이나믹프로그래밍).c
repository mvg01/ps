#include <stdio.h>

int dp[10001][3];
int main()
{	
	// 더하기 순서는 오름차순이라고 생각한 후
	// dp[i][0]: 1로 끝나는 경우
	// dp[i][1]: 2로 끝나는 경우
	// dp[i][2]: 3으로 끝나는 경우
	dp[1][0] = 1;  // 1
	dp[2][0] = 1;  // 1+1
	dp[2][1] = 1;  // 2
	dp[3][0] = 1;  // 1+1+1
	dp[3][1] = 1;  // 1+2
	dp[3][2] = 1;  // 3

	for (int i = 4; i < 10001; i++) {
		dp[i][0] = 1;     //1로 끝나는 것은 어차피 1+1+1 ... +1 이므로 1개
		dp[i][1] = dp[i - 2][0] + dp[i - 2][1];   //i의 -2 한 dp에서 1로 끝나는 것과 2로 끝나는 것 에 마지막으로 2를 더한다.
		dp[i][2] = dp[i - 3][0] + dp[i - 3][1] + dp[i - 3][2]; 
	}

	int t, n;
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		printf("%d\n", dp[n][0] + dp[n][1] + dp[n][2]);
	}
}