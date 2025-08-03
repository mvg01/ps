#include <stdio.h>

int a[100001];
int sum[100005];
int main()
{
	int k, n, i;
	scanf("%d %d", &n, &k);
	for (i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] += sum[i - 1] + a[i];  //누적합
	}

	int max = 0, check = 0, idx = n - k + 1;
	for (i = k; ; i++)
	{
		if (check==n)  //반복문이 도는 횟수는 n번임
			break;

		int x = 0;
		if (i > n) //바깥쪽으로 돌아야한다면 ex 4번째 파이 + 1번째 파이 
		{
			x += sum[n] - sum[idx];  //idx의 첫번째 값으론 n-k+1이 들어간다. 모든 파이의 합에서 idx 까지의 파이의 합을 빼준다.
			x += sum[i % n];  //바깥쪽으로 돌았으니 n으로 모듈러 연산을 해주면 sum[1] 값 부터 더하게 된다. 
			if (x > max)
				max = x;
			//printf("%d ", x);
			idx++;
		} 
		else {
			if (sum[i] - sum[i - k] > max)
				max = sum[i] - sum[i - k];
			//printf("%d ", sum[i] - sum[i - k]);
		}
		check++;
	}	
	printf("%d", max);
}

/*
문제를 해결 할 수 있었던 반례 
4 3
5 2 3 4
ans: 12 (10,9,12,11 순으로 값이 구해짐)
*/

