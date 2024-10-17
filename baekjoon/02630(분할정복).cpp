#include <iostream>
#include <cmath>
using namespace std;

int map[129][129];
int go[4][2] = { {0,0},{0,1},{1,0},{1,1} };
int white = 0;
int blue = 0;

int chk(int n, int y, int x) {
	int cnt = 0;
	for (int i = 0; i < n / 2; i++) {
		for (int j = 0; j < n / 2; j++) {
			if (map[i + y][j + x] == 1)
				cnt++;
		}
	}
	if (cnt == n * n / 4)  //파란색으로 꽉참
		return 1;
	else if (cnt == 0)  //흰색으로 꽉참
		return -1;
	else
		return 0;
}

void f(int n, int y, int x) {
	if (n == 2) {
		int cnt = 0;
		for (int i = 0; i < 4; i++) {
			if (map[y + go[i][0]][x + go[i][1]] == 1)
				cnt++;
		}

		if (cnt == 4)
			blue++;
		else if (cnt == 0)
			white++;

		else {
			blue += cnt;
			white += 4 - cnt;
		}
		return;
	}

	else {
		for (int i = 0; i < 4; i++) {
			int pp = chk(n, y + n / 2 * go[i][0], x + n / 2 * go[i][1]);

			if (pp == 1)
				blue++;
			else if (pp == -1)
				white++;
			else
				f(n / 2, y + n / 2 * go[i][0], x + n / 2 * go[i][1]);

			//cout << white << ' ' << blue << '\n';
		}
	}
}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> map[i][j];
		}
	}
	int first = chk(n * 2, 0, 0);
	if (first == 1)
		blue++;
	else if (first == -1)
		white++;
	else
		f(n, 0, 0);

	cout << white << '\n' << blue;
}