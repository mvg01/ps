#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char revs[2601][51];  // 51*51 
int main()
{
	int i, j, len, idx = 0;  
	char s[51];
	scanf("%s", s);
	len = strlen(s);
	for (i = 1; i < len; i++)
	{
		for (j = 1; j < len; j++)
		{
			if (i + j >= len)  //세번째 공간 창출 불가능
				continue;
		
			for (int k = 0; k < i; k++) {  //첫번째 0 ~ i
				revs[idx][k] = s[i - k - 1];
				//printf("%c", revs[idx][k]);
			}
			for (int k = i; k < i + j; k++) {  //두번째 i ~ i + j
				revs[idx][k] = s[(i * 2) + j - k - 1];
				//printf("%c", revs[idx][k]);
			}
			
			for (int k = i + j; k < len; k++) {  //세번째 i + j ~ len
				revs[idx][k] = s[(i + j) + len - k - 1];
				//printf("%c", revs[idx][k]);
			}
			revs[idx][len] = '\0';
			//printf("\n");
			idx++; //만들 수 있는 모든 경우의 수
		}
	}
	qsort(revs, idx, sizeof(char) * 51, strcmp);  //compare 함수를 strcmp로 사전순 비교
	printf("%s", revs[0]);
}