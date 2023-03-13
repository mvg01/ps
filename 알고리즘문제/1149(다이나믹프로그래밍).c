#include <stdio.h>
#define MIN(a,b)(a<b?a:b)  //#define 괄호 안쳐서 1시간 해맴 까먹지 않기
int red[1001];
int green[1001];
int blue[1001];
int dp[1001][3] = { 0 };
int main(void)
{
	int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d %d %d", &red[i], &green[i], &blue[i]); //red,green,blue를 2차원배열로 묶어도 되지만 보기 쉽게 하려고..
	dp[0][0] = red[0];
	dp[0][1] = green[0];
	dp[0][2] = blue[0];
	for (i = 1; i < n; i++) {
		dp[i][0] = MIN(dp[i - 1][1], dp[i - 1][2]) + red[i]; //전 값의 dp값이 초록or파랑을 더했을 때의 최솟값에 red의 i값을 더해줌
		dp[i][1] = MIN(dp[i - 1][0], dp[i - 1][2]) + green[i];
		dp[i][2] = MIN(dp[i - 1][0], dp[i - 1][1]) + blue[i];
		//printf("%d %d %d\n", dp[i][0], dp[i][1], dp[i][2]); // 변화되는 dp값을 확인하는 코드
	}
	int min = 1000000;   //1000*1000 
	for (i = 0; i < 3; i++) {
		if (min > dp[n - 1][i])
			min = dp[n - 1][i];
	}
	printf("%d", min);
}