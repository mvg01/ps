#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char s[100001];
int a[100001];
int static c(int* a, int* b)
{
	if (*a > *b)
		return 1;
	else if (*a < *b)
		return -1;
	else
		return 0;
}

int main()
{	
	scanf("%s", s);
	int len = strlen(s), sum = 0;
	for (int i = 0; i < len; i++)
		a[i] = s[i] - 48;

	qsort(a, len, 4, c);
	for (int i = 0; i < len; i++)
		sum += a[i];
	if (a[0] == 0 && sum % 3 == 0)
	{
		for (int i = len - 1; i >= 0; i--)
			printf("%d", a[i]);
	}
	else
		printf("-1");
}