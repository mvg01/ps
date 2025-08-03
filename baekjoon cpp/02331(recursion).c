#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int a, p;
int res;
int visited[236197] = { 0 };  //9^5 * 4
int arr[10000];
int re;  //반복된 숫자

void dfs(int num, int cnt) {
	if (visited[num] > 1) {
		//나왔던 숫자가 두 번 나왔을 때 -> 반복
		re = num;
		return;
	}

	arr[cnt] = num;
	visited[num]++;
	int temp = 0;
	for (int i = 0; i < 6; i++) {
		if (num / 10 > 0) {
			temp += (int)pow(num % 10, p);
			num /= 10;
		}
		else {
			temp += (int)pow(num % 10, p);
			visited[temp]++;
			break;
		}
	}
	printf("%d ", temp);
	dfs(temp, cnt + 1);  //반복되는 숫자가 나올 때 까지 탐색
	
	for (int i = cnt; i >= 0; i--) {
		if (arr[i] == re) {
			res = i;
			break;
		}
	}
}

int main()
{
	scanf("%d %d", &a, &p);
	dfs(a, 0);
	printf("%d", res);
}