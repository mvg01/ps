#include <stdio.h>

int a[100001];
int main()
{
	int n, s;
	scanf("%d %d", &n, &s);
	for (int i = 0; i < n; i++)
		scanf("%d", &a[i]);

	int sum = 0, left = 0, right = 0, len = 0;
	int min = 100000;
	while (left <= right)
	{
		if (left == n)
			break;

		if (sum <= s) {
			if (right < n) {  //먼저 간 포인터가 끝 지점에 도달 하기 전
				sum += a[right++];
				len++;
			}
			else {   //먼저 간 포인터가 끝에 도달했을 때 부턴 뒤의 포인터를 증가시켜줌
				sum -= a[left++];
				len--;
			}
		}
		else {  //(sum > s)
			sum -= a[left++];
			len--;
		}

		if (sum >= s) //sum s보다 긴 순간 
		{
			if (min >= len)
				min = len;
		}
	}
	if (min != 100000)
		printf("%d", min);
	else
		printf("0");
}