#include <stdio.h>

unsigned long long a[36]; //자료형 주의
void f(void)
{
	a[0] = 1;
	a[1] = 1;
	a[2] = 2;
	for (int i = 3; i <= 35; i++)
		for (int j = 0; j < i; j++)
			a[i] += a[j] * a[i - j - 1];  //문제의 점화식이다.
}

int main()
{
	int n;
	scanf("%d", &n);
	f();
	printf("%lld", a[n]);
}