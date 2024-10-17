#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int sumchar(char* s) {
	int len = strlen(s), sum = 0;
	for (int i = 0; i < len; i++) {
		if (s[i] <= '9') {
			sum += s[i] - '0';
		}
	}
	return sum;
}

int static c(char* a, char* b)
{
	int alen = strlen(a);
	int blen = strlen(b);
	int asum, bsum;
	if (alen > blen)
		return 1;
	else if (alen < blen)
		return -1;
	else {  //길이가 같으면
		asum = sumchar(a);
		bsum = sumchar(b);
		if (asum > bsum)
			return 1;
		else if (asum < bsum)
			return -1;
		else {  //자리수의 합도 같다면
			return strcmp(a, b);
		}
	}
}
int main()
{	
	int n;
	char str[51][51];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%s", str[i]);
	qsort(str, n, sizeof(str[0]), c);
	for (int i = 0; i < n; i++)
		printf("%s\n", str[i]);
}