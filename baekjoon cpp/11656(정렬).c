#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char a[1001][1001];
int static compare(char* a, char* b)
{
	if (strcmp(a,b)>0)  //b가 a보다 사전 순으로 앞에있다면 양수 반환
		return 1;  
	else if (strcmp(a,b)<0)
		return -1;
	else {  //만약 모두 같은 문자라면 길이비교 더 짧은 것이 앞으로
		if(strlen(a)>strlen(b))  
			return 1;
		else
			return -1;
	}
}
int main()
{
	char s[1001];
	scanf("%s", s);
	int len, i;
	len = strlen(s);
	for (i = 0; i <len; i++)
	{
		int idx = 0;
		for (int j = i; j < len; j++) 
			a[i][idx++] = s[j];

		a[i][len-i] = '\0';
	}
	qsort(a, len, sizeof(a[i]), compare);
	for (i = 0; i < len; i++)
		printf("%s\n", a[i]);
}


/*
   반례 aaa
ans:
a
aa
aaa

*/
