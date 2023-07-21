#include <stdio.h>
#include <stdlib.h>

int num[1000] = { 0 };
int main()
{
	int n;
	char tmp[4]; 
	char tmp2[4];
	scanf("%d", &n);
    //문제조건
	for (int i = 0; i < 123; i++) 
		num[i] = 0;
	for (int i = 123; i < 1000; i++) {
		sprintf(tmp2, "%d", i);
		if (tmp2[0] == tmp2[1] || tmp2[1] == tmp2[2] || tmp2[0] == tmp2[2])
			num[i] = 0;
		else if (tmp2[0] == '0' || tmp2[1] == '0' || tmp2[2] == '0')
			num[i] = 0;
		else
			num[i] = 1;
	}
	
	int x, a, b;
	for (int i = 0; i < n; i++) {
		scanf("%d %d %d", &x, &a, &b);
        
        //모든 숫자 경우에 대해서 검사하기 (최대 100 * 504)
		for (int j = 123; j < 999; j++) {
			int tmp_strike = 0;
			int tmp_ball = 0;		

			if (num[j] != 0) {
                //문자열 혹은 모듈러연산으로 비교가능
				sprintf(tmp, "%d", x);
				sprintf(tmp2, "%d", j);
				for (int c = 0; c < 3; c++) {
					for (int d = 0; d < 3; d++) {
						if (c == d && tmp[c] == tmp2[d]) //스트라이크 체크
							tmp_strike++;
						if (c != d && tmp[c] == tmp2[d]) //볼 체크
							tmp_ball++;
					}
				}
				if (tmp_strike == a && tmp_ball == b)
					num[j] = 1;
				else
					num[j] = 0;
			}
		}
	}
	int res = 0;
	for (int i = 123; i < 999; i++)
	{
		if (num[i] == 1) {
			res++;
			//printf("%d ", i);
		}
	}
	printf("%d", res);	
}