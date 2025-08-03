#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[1000001][21];
char res[500001][21];
int cnt = 0;
int static compare(char* a[], char* b[])
{
	if (strcmp(a, b) > 0)
		return 1;
	else if (strcmp(a, b) < 0)
		return -1;
	else {
		strcpy(res[cnt], a);  //같다면 res에 저장
		cnt++;
		return 0;
	}
}
int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n + m; i++)
		scanf("%s", s[i]);
	qsort(s, n + m, sizeof(s[0]), compare);  //n+m 전체 문자열 정렬
	printf("%d\n", cnt);
	qsort(res, cnt, sizeof(res[0]), compare);  //res 사전순 정렬
	for (int i = 0; i < cnt; i++)
		printf("%s\n", res[i]);
}

