#include <stdio.h>

//에라토스테네스의 체
int number = 4000000;
int a[4000001];
void primeNumber(int x, int y, int d) {
	int count = 0;
	for (int i = 2; i <= number; i++)
		a[i] = i; 

	for (int i = 2; i <= number; i++)
	{
		if (a[i] == 0)
			continue;
		for (int j = i + i; j <= number; j += i)
			a[j] = 0;
	}
	for (int i = x; i <= y; i++)
		if (a[i] != 0) {
			while (1) {
				if (a[i] % 10 == d) {
					count++;
					break;
				}
				if (a[i] <= 0)
					break;
				a[i] /= 10;
			}
		}
	printf("%d", count);
}

int main(void)
{
	int a, b, d;
	scanf("%d %d %d", &a, &b, &d);
	primeNumber(a,b,d);
}
