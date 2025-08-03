#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n;
int a[2188][2188];
int res1 = 0, res2 = 0, res3 = 0; //각각 -1,0,1 개수

void divide(int p, int y, int x) {
	if (p == 1) {  //종이가 1X1까지 나눠졌을 때
		if (a[y][x] == -1)
			res1++;
		else if (a[y][x] == 0)
			res2++;
		else if (a[y][x] == 1)
			res3++;
		return;
	}

	bool brk = 0;  //PxP의 범위에서 하나라도 다른 숫자가 있을 땐 분할해야함 -> brk = true
	int point = a[y][x];
	for (int i = y; i < y + p; i++) {
		for (int j = x; j < x + p; j++) {
			if (point != a[i][j]) {
				brk = 1;
				break;
			}
		}
		if (brk)
			break;
	}

	if (brk) {  //9개로 분할해야함
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divide(p / 3, y + (p / 3 * i), x + (p / 3 * j));
			}
		}
	}
	else {  //분할하지 않고 PxP가 모두 같은 숫자인 경우
		if (point == -1)
			res1++;
		else if (point == 0)
			res2++;
		else if (point == 1)
			res3++;
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> a[i][j];
	}
	divide(n, 0, 0);

	cout << res1 << '\n' << res2 << '\n' << res3;
}