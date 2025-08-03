#include <stdio.h>

int n;
int max = 0;

void bt(int w[], int size, int e) {
	if (size == 3) {
		e += w[0] * w[2];
		if (max < e)
			max = e;
		return;
	}

	//백트래킹으로 모든 경우의 수 탐색
	for (int i = 1; i < size - 1; i++) {
		int temp[1001];
		int idx = 0;
		for (int j = 0; j < size; j++) {
			if (j != i)
				temp[idx++] = w[j];
		}
		e += w[i + 1] * w[i - 1];
		bt(temp, size - 1, e);
		e -= w[i + 1] * w[i - 1];
	}
}


int main() 
{
	int w[1001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		scanf("%d", &w[i]);

	bt(w, n, 0);  //w 에너지 배열, n 구슬 개수, 현재 에너지

	printf("%d", max);
}