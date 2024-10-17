#include <stdio.h>
#include <math.h>

int number = 10000;
int a[10001];
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

int solve(int m)
{
	int temp = m, chk = 0;  //chk는 행복인지 아닌지 bool 값
	int check[1000] = { 0 };  //나왔던 수가 또 나오면 그 수는 행복한 수가 아님
	while (1)
	{
		int sum = 0;
		while (temp > 0) {
			sum += (int)pow(temp % 10, 2);
			temp /= 10;
		}

		if (sum == 1) {
			chk = 1;
			break;
		}

		if (check[sum] == 0) //아직 나오지 않은 연산이었다면
			check[sum] = 1;
		else  //나온 연산 결과였다면 무한반복이니 chk=0 인 채로 탈출
			break;

		//printf("%d ", sum);
		temp = sum;
	}
	return chk;
}

int main()
{
	primeNumber();
	//a[1] = 0;
	int p, x, m;
	scanf("%d", &p);
	for (int i = 1; i <= p; i++)
	{
		scanf("%d %d", &x, &m);
		if (a[m] == 0)
			printf("%d %d NO\n", i, m);
		else
		{
			if(solve(m))
				printf("%d %d YES\n", i, m);
			else
				printf("%d %d NO\n", i, m);
		}
	}
}