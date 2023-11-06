#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char res[5050][101];
int static compare(char* a, char* b)
{
	if (strlen(a) > strlen(b))
		return 1;
	else if (strlen(a) < strlen(b))
		return -1;
	else {
		if (strcmp(a, b) > 0)
			return 1;
		else
			return -1;
	}
}

int main()
{
	int n, x, len, idx = 0, not_end = 0;
	char str[101], temp[101];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", str);
		len = strlen(str);
		not_end = 0;

		for (int j = 0; j < len; j++)
		{
			int point = 0, chk = 0, tempidx = 0;

			if (j == len - 1)  //마지막 문자 처리
				not_end = 1;

			if (str[j] >= '0' && str[j] <= '9')
			{
				for (int p = 0; p < 101; p++)
					temp[p] = '\0';

				if (str[j] == '0') {  //맨 앞자리가 0인 경우 따로
					for (int k = j; k < len; k++) {
						if (k == len - 1)  //마지막 문자 처리
							not_end = 1;

						if (str[k] >= '1' && str[k] <= '9') {
							temp[tempidx++] = str[k];
							point++;
							chk = 1;
						}
						else if (str[k] == '0' && chk == 1) {//0으로 시작하는 수 중에 00101 등 0이 아닌 숫자가 시작되었을 때
							temp[tempidx++] = str[k];
							point++;
						}

						else if (str[k] == '0' && chk == 0)
							point++;

						else {
							if (chk) {  //0으로 시작했지만 중간에 숫자가 형성된 경우
								temp[tempidx] = '\0';
								strcpy(res[idx++], temp);
								j += point;  //숫자 나온만큼 배열 밀어주기
								break;
							}
							else { //0으로 시작해서 0만 나온 숫자인 경우
								temp[0] = '0'; temp[1] = '\0';
								strcpy(res[idx++], temp);
								j += point;
								break;
							}
						}
					}
					if (str[j] >= '0' && str[j] <= '9'&&not_end) {  //마지막을 위한 문자열 처리일 때
						if (chk) {  
							temp[tempidx] = '\0';
							strcpy(res[idx++], temp);
							j += point;  
						}
						else { 
							temp[0] = '0'; temp[1] = '\0';
							strcpy(res[idx++], temp);
							j += point;
						}
					}
				}

				else {
					for (int k = j; k < len; k++) {
						if (k == len - 1)  //마지막 문자 처리
							not_end = 1;

						if (str[k] >= '0' && str[k] <= '9')
							temp[point++] = str[k];
						else
						{
							temp[point] = '\0';
							strcpy(res[idx++], temp);
							j += point;
							break;
						}
					}

					if (str[j] >= '0' && str[j] <= '9' && not_end) {  //마지막을 위한 문자열 처리일 때
						temp[point] = '\0';
						strcpy(res[idx++], temp);
						j += point;
					}
				}
				//printf("%s\n", temp);
			}
		}
	}
	//printf("%d\n", idx);
	qsort(res, idx, sizeof(res[0]), compare);
	for (int i = 0; i < idx; i++)
		printf("%s\n", res[i]);
}