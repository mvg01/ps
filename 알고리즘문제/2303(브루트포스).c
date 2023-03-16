#include <stdio.h>
#include <stdlib.h>
int main()
{
	int n, i;
	int c[1001][5];
	int* max;
	scanf("%d", &n);
	max = (int*)malloc(n * sizeof(int));  
	for (i = 0; i < n; i++)
	{
		for (int j = 0; j < 5; j++)
			scanf("%d", &c[i][j]);
	}

	for (i = 0; i < n; i++)
	{
		int sum = -1;
		for (int j = 0; j < 3; j++) {  //3개의 수 합 %10 해서 가장 큰 값 기억.  3중 for문 말고 더 좋은 방법이 있을까요?
			for (int k = j + 1; k < 4; k++) {
				for (int l = k + 1; l < 5; l++) {
					if (sum < (c[i][j] + c[i][k] + c[i][l]) % 10)
						sum = (c[i][j] + c[i][k] + c[i][l]) % 10;
				}
			}
		}
		max[i] = sum;  //가장 컸던 합을 max에 저장
	}
	int maxsum = -1, idx = 0;
	for (i = 0; i < n; i++) {
		if (maxsum <= max[i]) {
			maxsum = max[i];
			idx = i + 1;   //구해야하는 것은 인덱스임
		}
		//printf("%d\n", max[i]);  //가장 큰 맥스값 확인
	}
	printf("%d", idx);
	free(max);
}