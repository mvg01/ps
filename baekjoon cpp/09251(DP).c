#include <stdio.h>
#include <string.h>
#define MAX(x,y) (((x)>(y)?(x):(y))

int dp[1005][1005];
int main()
{
	char a[1005], b[1005];
	scanf("%s %s", a, b);
	int alen, blen;
	alen = strlen(a);
	blen = strlen(b);

	for (int i = 1; i <= alen; i++) {
		for (int j = 1; j <= blen; j++) {
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = MAX(dp[i - 1][j], dp[i][j - 1]));
		}
	}
	printf("%d", dp[alen][blen]);
}

//LCS에 관련된 설명 (참고)
//https://velog.io/@emplam27/%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-%EA%B7%B8%EB%A6%BC%EC%9C%BC%EB%A1%9C-%EC%95%8C%EC%95%84%EB%B3%B4%EB%8A%94-LCS-%EC%95%8C%EA%B3%A0%EB%A6%AC%EC%A6%98-Longest-Common-Substring%EC%99%80-Longest-Common-Subsequence#longest-common-subsequence-substring