#include <stdio.h>

int number = 1000000;
int x[10001];
int check[1000001];
int a[1000001];

void primeNumber() {
	for (int i = 2; i <= number; i++)
		a[i] = i;

	for (int i = 2; i <= number; i++)
	{
		if (a[i] == 0)
			continue;
		for (int j = i + i; j <= number; j += i)
			a[j] = 0;
	}
}
int main()
{
	int n, i;
	long long s = 1;
	primeNumber();
	scanf("%d", &n);
	for (i = 0; i < n; i++) {
		scanf("%d", &x[i]);
		if (check[x[i]] == 0) {
			if (a[x[i]] != 0)
				s *= x[i];
		}
		check[x[i]] = 1;
	}
	if (s != 1)
		printf("%lld", s);
	else
		printf("-1");
}  

/* 처음 틀린 제출의 반례
5
2 2 2 2 2
ans : 2
check 배열로 해결
*/ 