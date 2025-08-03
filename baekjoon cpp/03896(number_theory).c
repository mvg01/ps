#include <stdio.h>

int number = 1299710;
int a[1299710];
void primeNumber() {
	for (int i = 2; i <= number; i++)
		a[i] = i;  //자기자신으로 배열값 초기화

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
	int t, i, k;
	scanf("%d", &t);
	primeNumber();
	for (i = 0; i < t; i++) {
		scanf("%d", &k);
		int j, c = 1;
		if (a[k] != 0)  // k가 소수이면 그냥 0
		{
			printf("0\n");
			continue;
		}

		for (j = k; j >= 2; j--)  //k가 합성수일 때 k보다 작은 소수를 j
		{
			if (a[j] != 0)
				break;
		}

		for (int l = j + 1; l <= 1299709; l++) //소수가 나올때까지 count 값을 늘려준다. c=1에서 시작 (j가 소수이기 때문)
		{
			if (a[l] == 0)
				c++;
			else
				break;
		}

		printf("%d\n", c);
	}
}