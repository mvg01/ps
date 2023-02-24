#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[20001][51];
int compare(char* first, char* second)
{
    if (strlen(first) > strlen(second))
        return 1;
    else if (strlen(first) < strlen(second))
        return -1;
    else 
        return strcmp(first,second);
}

int main(void)
{
    int n, i;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
		scanf("%s", s[i]);

    qsort(s, n, sizeof(s[0]), compare);

    printf("%s\n", s[0]);
    for (i = 1; i < n; i++) {
        if (strcmp(s[i], s[i - 1]) == 0)
            continue;
        printf("%s\n", s[i]);
    }
}