#include <stdio.h>

int a[10001];
int main(void)
{
	int n, m, t = 0;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int start = 0, end = 0, sum = 0;
	while (n >= end) //end가 n이상이 되면 탈출
	{
        if (m == sum)
			t++;

		if (m > sum)  //sum값이 목표값인 m을 넘지 못했다면
			sum += a[end++];
		else   // m <= sum 
			sum -= a[start++]; //연속된 수열의 첫 값을 빼준다.
	}
    
	printf("%d", t);
}