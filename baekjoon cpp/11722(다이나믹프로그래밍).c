#include <stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))

int dp[1005] = {0};
int main()
{
	int a[1001], n, res = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++) {
		dp[i] = 1;  //초기값 1 (수열의 길이가 1개면 1임)
		for (int j = 1; j < i; j++) { 
			if (a[i] < a[j])  //비교하고자 하는 인덱스 번호값보다 크면 감소이므로
				dp[i] = MAX(dp[i], dp[j] + 1); //가장 길었던 부분수열 길이 or 1더한 길이
		}
		if (res < dp[i])
			res = dp[i];
	}	
	
	printf("%d", res);
}