#include <stdio.h>
#define MAX(a,b)(a>b?a:b)
int dp[100001];
int a[100001];
int main(void)
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	dp[0] = a[0];  //초기값
	for (int i = 1; i < n; i++)
	{
		dp[i] = MAX(a[i], dp[i - 1] + a[i]); 
		//printf("%d ", dp[i]);  //dp값 확인용 출력문
	}
	int max = -1000; //답이 음수일수가 있음 주의
	for (int i = 0; i < n; i++)
		if (max < dp[i])
			max = dp[i];
	printf("%d", max);
}

//핵심은  14번째 줄
//dp[i]는 a[i] or dp[i-1]+a[i] 중 큰 값을 저장해서 max값을 기억하게 해준다.