#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[20001][51];
int compare(char* first, char* second)  //문자열 퀵정렬 
{
    if (strlen(first) > strlen(second)) //일단 문자열의 길이를 비교해서 크기를 비교해서 정렬
        return 1;
    else if (strlen(first) < strlen(second)) 
        return -1;
    else  //문자열의 길이가 같다면?
        return strcmp(first,second);  //가장 앞 문자의 사전순으로 비교하기 위한 strcmp
}

int main(void)
{
    int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);

    qsort(s, n, sizeof(s[0]), compare);

    printf("%s\n", s[0]);
    for (i = 1; i < n; i++) {  //중복된 문자열은 제거해줘야 한다.
        if (strcmp(s[i], s[i - 1]) == 0)  // 정렬된 문자열에서 중복된 배열이면 출력하지 않고 continue;
            continue;
        printf("%s\n", s[i]);
    }
}