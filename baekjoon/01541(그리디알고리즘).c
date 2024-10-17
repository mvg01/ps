#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int len, res = 0, a[50];
	char str[51], num[9];
	scanf("%s", str);
	len = strlen(str);

	int ten = 1, temp = 0, chk = 1, idx = 0, numidx = 0;
	for (int i = 0; i < len; i++) {

		if (str[i] >= '0' && str[i] <= '9') {  

			if (temp == 0 && str[i] == '0')
				continue;
			else {
				num[numidx++] = str[i];
			}
		}

		else {
			numidx = 0;
			if (chk == 1 && str[i] == '-') //처음 나온 마이너스라면
			{
				chk = 0;
				a[idx++] = temp;
				ten = 1;
				temp = 0;
			}
			else if (chk == 0)  // '-' 이후는 모두 뺀다.
			{
				a[idx++] = temp * -1;
				ten = 1;
				temp = 0;
			}
			else { //'+' 일땐 그냥 더해준다.
				a[idx++] = temp;
				ten = 1;
				temp = 0;
			}
		}
		num[numidx] = '\0';
		//printf("%s ", num);
		temp = atoi(num);
	}
	//마지막 숫자 처리
	if (chk)  
		res += temp;
	else
		res += temp * -1;


	for (int i = 0; i < idx; i++)
		res += a[i];

	printf("%d", res);
}