#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char str[1001][51];
int static c(char* a, char* b) {
	return strcmp(a, b);
}

int main()
{	
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) 
		scanf("%s", str[i]);

	qsort(str, n, sizeof(str[0]), c); //오름차순 정렬 a~z

	int max = 1, maxidx = 0, cnt = 1;
	for (int i = n - 2; i >= 0; i--) {  //숫자가 같다면 알파벳 순서이므로 뒤에서부터

		if (!strcmp(str[i + 1], str[i]))
			cnt++;

		else {
			cnt = 1;
		}

		if (max <= cnt) {
			max = cnt;
			maxidx = i;
		}
	}
	printf("%s", str[maxidx]);
}