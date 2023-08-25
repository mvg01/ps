#include <iostream>
#include <cmath>
using namespace std;

int n;
char map[3073][6145];
void bt(int size, int y, int x) {
	if (size == 3) {
		map[y][x] = '*';
		map[y + 1][x - 1] = '*'; map[y + 1][x + 1] = '*';
		for (int i = x - 2; i <= x + 2; i++)
			map[y + 2][i] = '*';
		return;
	}

	bt(size / 2, y, x);
	bt(size / 2, y + size / 2, x - size / 2);
	bt(size / 2, y + size / 2, x + size / 2);
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			map[i][j] = ' ';
		}
	}
	bt(n, 0, n - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n * 2; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}
}