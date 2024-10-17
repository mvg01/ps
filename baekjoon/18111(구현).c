#include <stdio.h>

int main()
{
	int n, m, b, i, j, x, max = 0;
	int height[257] = { 0 };
	scanf("%d %d %d", &n, &m, &b);
	for (i = 0; i < n * m; i++) {
		scanf("%d", &x);
		if (max < x)
			max = x;
		height[x]++;
	}
	int min_time = 500 * 500 * 256, res_h = 0;  //min_time의 초기값은 가장 오래 걸릴 수 있는 시간으로
	for (i = max; i >= 0; i--) {
		int time = 0;
		int block = b; 
		for (j = 0; j < 257; j++) {
			if (i - j < 0) {  //블록 제거해서 인벤토리 넣기
				time += 2 * (j - i) * height[j];
				block += (j - i) * height[j];
			}
			else if (i - j > 0) {  //블록 추가해서 인벤토리 추가
				time += (i - j) * height[j];
				block -= (i - j) * height[j];
			}
		}

		if (block >= 0 && min_time > time) {  //인벤토리가 0 이상이고 가장 시간이 적게걸린
			min_time = time;
			res_h = i;  //높이 저장
		}
	}
	printf("%d %d", min_time, res_h);
}

/*  사용한 반례 모음

3 4 11
29 51 54 44
22 44 32 62
25 38 16 2

ans 250 30

4 4 36
15 43 61 21
19 33 31 55
48 63 1 30
31 28 3 8

ans 355 32

*/
