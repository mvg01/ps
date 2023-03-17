#include <stdio.h>

int number = 1000; 
int a[1000];
void primeNumber() {   //에라토스테네스의 체
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
	int n, x;
	scanf("%d", &n);
	primeNumber();  
	int i, j, k, l;
	for (i = 0; i < n; i++)
	{
		scanf("%d", &x);
        
		for (j = 2; j <= x; j++) {
			for (k = 2; k <= x; k++) {
				for (l = 2; l <= x; l++) {
					if (a[l] != 0 && a[k] != 0 && a[j] != 0)
					{
						if (j + k + l == x) {
							printf("%d %d %d\n", j, k, l);
							break;
						}
					}
				}
				if (j + k + l == x)
					break;
			}
			if (j + k + l == x)
				break;
		}
	}
}