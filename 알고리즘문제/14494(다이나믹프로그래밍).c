#include <stdio.h>
#include <stdlib.h>

long long dp[1001][1001] = { 0 };

void f() {
	for (int i = 1; i <= 1000; i++) {
		dp[1][i] = 1;
		dp[i][i] = 1;
		dp[i][1] = 1;
	}
	for (int i = 2; i <= 1000; i++) {
		for (int j = 2; j <= 1000; j++) {
			dp[i][j] = (dp[i - 1][j] + dp[i][j - 1] + dp[i - 1][j - 1]) % 1000000007;
		}
	}	
}

int main() 
{
	int a, b;
	scanf("%d %d", &a, &b);
	f();
	printf("%lld", dp[a][b]);
}