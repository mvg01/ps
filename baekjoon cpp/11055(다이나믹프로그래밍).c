#include <stdio.h>

int dp[1005] = {0};
int main()
{
	int a[1001], n, res = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++)  //1번부터 i번까지
	{
		dp[i] = a[i];  //a[i]가 가장 큰 값일 때로
		for (int j = 1; j < i; j++) 
		{
			if (a[i] > a[j] && dp[j] + a[i] > dp[i])
				dp[i] = dp[j] + a[i];
		}
		if (res < dp[i])
			res = dp[i];
		//printf("%d ", dp[i]);
	}
	printf("%d", res);
}