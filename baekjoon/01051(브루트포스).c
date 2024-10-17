#include <stdio.h>

int main()
{
	int n, m;
	char a[51][51];
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
		scanf("%s", a[i]);

	int min = n < m ? n : m; //최소 크기는 n과 m중 작은 숫자부터 시작한다.
	
	while (min--) {
		for (int i = 0; i < n - min; i++)
		{
			for (int j = m - 1; j >= min; j--)
			{
                //꼭짓점 4개 다 같은 숫자인지 확인하는 조건문
				if (a[i][j] == a[i][j - min] && a[i + min][j] == a[i + min][j - min] && a[i+min][j] == a[i][j - min]) { 
					min += 1;
					printf("%d", min * min);
					return 0;
				}
			}
		}
	}
	printf("1");
}	