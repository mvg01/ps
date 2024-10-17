#include <stdio.h>
#include <stdlib.h>

int number = 50000;
int a[50001];
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
	primeNumber();
	int prime[5140] = { 0 }, idx = 0;  //5133개
	for (int i = 2; i <=50000; i++)
	{
		if (a[i] != 0) {
			prime[idx] = i;
			//printf("%d " ,prime[idx]);
			idx++;
		}
	}

	int t, n;
	scanf("%d", &t);
	while (t--)
	{
		int min = 10000000;
		scanf("%d", &n);
		for (int i = 5132; i >= 0; i--)
		{
			for (int j = i; j >= 0; j--)
			{
				if (i != j)
				{
					if (min > prime[i] * prime[j] && prime[i] * prime[j] >= n)
						min = prime[i] * prime[j];
				}
			}
		}
		printf("%d\n", min);
	}
}

