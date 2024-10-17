#include <stdio.h>
#include <stdlib.h>

int main()
{
	int t, r, c, i, j;
	char** candy;   //candy[r][c] 동적할당 위한 이중포인터
	scanf("%d", &t);
	while (t--) {
		int cnt = 0;
		scanf("%d %d", &r, &c);

		candy = (char**)malloc(sizeof(char*) * r);
		for (i = 0; i < r; i++)
			candy[i] = (char*)malloc(sizeof(char) * c);

		for (i = 0; i < r; i++) {
			for (j = 0; j < c; j++)
				scanf(" %c", &candy[i][j]);  //white space
		}
		if (r < 3 && c < 3) {  //0이 될 수 밖에 없음
			printf("0\n");
			continue;
		}

		for (i = 0; i < r; i++)
		{
			for (j = 0; j < c - 2; j++) {
				if (candy[i][j] == '>' && candy[i][j + 1] == 'o' && candy[i][j + 2] == '<')
					cnt++;
			}
		}

		for (i = 0; i < c; i++)
		{
			for (j = 0; j < r - 2; j++) {
				if (candy[j][i] == 'v' && candy[j + 1][i] == 'o' && candy[j + 2][i] == '^')
					cnt++;
			}
		}

		printf("%d\n", cnt);
		for (i = 0; i < r; i++)
			free(candy[i]);
		free(candy);
	}
}

/*
한번 걸렸던 반례
1
2 6
>o<>o<
>o<>o<
ans:4

*/