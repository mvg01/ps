#include <stdio.h>

int number = 1500000;  //문제에서 n값은 10^6 까지이다 따라서 n이 10^6이 들어가면 10^6보다 큰 소수이자 팰린드롬을 찾아야하기 때문에 넉넉하게 줬다.
int a[1500001];
void primeNumber() {  //에라토스테네스의 체
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

int rev(int n) {  //팰린드롬 체크 (정수로 받고 정수 뒤집어서 같은지 확인)
	int x = 0, y = n;
	int ten = 1;
	for (int i = 1; i <= 1000000; i *= 10) {
		if (ten > n)
			break;
		ten *= 10;
	}
	ten /= 10;
	while (y) {
		x += (y % 10) * ten;
		y /= 10;
		ten /= 10;
	}
	if (x == n)
		return 1;  //팰린드롬 이라면 1 return 
	else
		return 0;
}

int main()
{
	int n;
	scanf("%d", &n);
	primeNumber();  
	for (int i = n; ; i++)
	{
		if (a[i] != 0 && rev(i) == 1) {  // 소수 && 팰린드롬 
			printf("%d", i); 
			break;
		}
	}
}