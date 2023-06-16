#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[300001];
int main()
{
	int n, st = 0, nt = 0, cnt, max = 0;
	scanf("%d", &n);
	scanf("%s", s);
	for (int i = 0; i < n; i++)
	{
		int maxlen = 1;
		cnt = 0;
		if (s[i] == 'N') {
			for (int j = i + 1; j < n; j++)
			{
				if (s[j] == 'S') {
					st = j;  //'S'가 시작되는 idx
					break;
				}
				maxlen++;
			}
			for (int j = st; j < st+maxlen; j++)
			{
				if (s[j] == 'N')
					break;
				if (j >= n)
					break;
				cnt += 2;  //막대자석 길이
			}

			if (cnt > max) 
				max = cnt;

			i += maxlen-1; //시간초과 없애주는 처리
			continue;
		}

		if (s[i] == 'S') {
			for (int j = i + 1; j < n; j++)
			{
				if (s[j] == 'N') {
					nt = j;  //'N'이 시작되는 idx
					break;
				}
				maxlen++;
			}
			for (int j = nt; j < nt+maxlen; j++)
			{
				if (s[j] == 'S')
					break;
				if (j >= n)
					break;
				cnt += 2;
			}

			if (cnt > max) 
				max = cnt;

			i += maxlen-1;
		}
	}

	if (!max)
		printf("0");
	else
		printf("%d", max);
}
