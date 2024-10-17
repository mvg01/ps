#include <stdio.h>

int len[10001];
int main()
{
	int n, k, max = 0;
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%d", &len[i]);
		if (max < len[i])
			max = len[i];
	}
	//start와 end를 더했을 때 int형 범위를 벗어날 수 있음 
	long long start = 1, end = max, mid = 0; 
	int x = 0;
	while (start<=end)  //len의 최대길이를 이분탐색으로
	{
		int lennum = 0;
		mid = (start + end) / 2;
		for (int i = 0; i < k; i++)
			lennum += len[i] / mid; 

		if (lennum >= n)
		{    //개수는 n개를 넘거나 같다. 가장 긴 랜선길이 저장
			if (x < mid)  
				x = mid;

			start = mid + 1; //더 긴 랜선길이 시도
		}
		else 
			end = mid - 1;  //n개를 넘기려면 랜선이 더 짧아져야 함
	}
	printf("%d", x);
}