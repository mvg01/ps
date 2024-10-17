#include <stdio.h>
#define MAX(a,b) ((a)>(b)?(a):(b))

int dp[1005] = {0};
int main()
{
	int a[1001], n, res = 0;
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
		scanf("%d", &a[i]);

	for (int i = 1; i <= n; i++)
	{
		dp[i] = 1;
		for (int j = 1; j < i; j++)
		{
			if (a[i] > a[j])
				dp[i] = MAX(dp[i], dp[j] + 1);
		}
		if (res < dp[i])
			res = dp[i];
	}
	printf("%d", res);
}