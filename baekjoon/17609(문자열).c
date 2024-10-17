#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char s[100001];
char temp[100001];
char a[100001];
char b[100001];

int p(char* s,int len) {  //회문인지 검사하는 함수 (O(N))
	for (int i = 0; i < len; i++) 
		temp[i] = s[len - 1 - i];
	temp[len] = '\0';
	return !strcmp(temp, s);
}
int main()
{
	int t,len;
	scanf("%d", &t);
	while (t--) {
		
		scanf("%s", s);
		len = strlen(s);
		if (p(s,len))  //기존 문자열 회문이면 0
			printf("0\n");

		else {  
            //아니라면 문자열의 앞,뒤에서부터 하나씩 비교하면서 만약 다르면 
            //각각 문자를 제거하고 두 문자열 모두 회문검사를 한다.
			int half = len / 2, chk = 0; 
			int aidx = 0, bidx = 0;
			for (int i = 0; i < half; i++) {
				if (s[i] != s[len - i - 1]) {
					for (int j = 0; j < len; j++) {
						if (j != i)
							a[aidx++] = s[j];
						if (j != len - i - 1)
							b[bidx++] = s[j];
					}
					a[aidx] = '\0';
					b[bidx] = '\0';

					//printf("%s %s\n", a, b);
					if (p(a, len - 1) || p(b, len - 1))
						printf("1\n");
					else
						printf("2\n");
					break;
				}
			}
		}
	}
}