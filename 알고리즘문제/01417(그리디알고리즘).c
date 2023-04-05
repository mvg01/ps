//풀이방식 : 가장 큰 표를 찾아서 그 표를 하나 매수하고 a[0]에 더해준다.
//           -> 다솜이 표가 가장 큰 표가 될 때 까지
#include <stdio.h>

int main(void)
{
	int a[51];
	int n, i, cnt = 0;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%d", &a[i]);

	while (1)
	{
		int maxvote = 0;
		int maxvoteindex = 0;
		for (i = 1; i < n; i++)   //매번 가장 큰 표수 찾기
		{
			if (maxvote <= a[i]) { 
				maxvote = a[i];
				maxvoteindex = i;
			}
		}

		if (a[0] > maxvote)  //다솜이가 이기는 순간 break
			break;
		else 
		{
			a[0]++;  //다솜이 표 추가
			a[maxvoteindex]--;  //가장컸던 애 감소
			cnt++;  //매수한명 추가
		}
	}
	printf("%d", cnt);
}