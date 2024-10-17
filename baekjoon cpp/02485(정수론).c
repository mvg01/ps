#include <stdio.h>

int a[100001];
int gcd(int x, int y)
{
	if (y == 0)
		return x;
	else
		return gcd(y, x % y);
}

int main()
{
	int n, i, y, cnt = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	y = a[1] - a[0];
	for (i = 0; i < n - 1; i++)  //가로수의 거리 최대공약수 갱신
	{
		y = gcd(y, a[i + 1] - a[i]);
		//printf("%d ", y);
	}
	for (i = 0; i < n - 1; i++)
		cnt += (a[i + 1] - a[i]) / y - 1;  //가로수들 사이의 거리를 최대공약수로 나눈후 1을 빼줘야함

	printf("%d", cnt);
}
