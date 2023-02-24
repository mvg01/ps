//첫번째 풀이

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int static compare(char* first, char* second)  // qsort 문자열 compare
{
	if (*first < *second)
		return 1;
	else if (*first > *second)
		return -1;
	else
		return 0;
}

int main(void)
{
	char s[11];
	int i, len;
	scanf("%s", s);
	len = strlen(s);
	qsort(s, len, sizeof(char), compare);
	printf("%s", s);
}

//두번째 풀이

#include <stdio.h>
#include <stdlib.h>
int static compare(int* first, int* second)  // qsort int형 정수 값 compare
{
	if (*first < *second)
		return 1;
	else if (*first > *second)
		return -1;
	else
		return 0;
}

int main(void)
{
	int n, m, i, len = 0, s[11];
	scanf("%d", &n);
	m = n;
	while (1) {
		if (m / 10 != 0) {
			len++;
			m /= 10;
		}
		else {
			len++;
			break;
		}
	}
	for (i = 0; i < len; i++)
	{
		s[i] = n % 10;
		n /= 10;
	}
	qsort(s, len, 4, compare);
	for (i = 0; i < len; i++)
		printf("%d", s[i]);
}