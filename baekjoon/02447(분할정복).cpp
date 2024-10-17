#include <iostream>
using namespace std;

char mat[2188][2188];

void f(int len, int y, int x) {
	if (len == 3) {
		for (int i = y; i < y + 3; i++) {
			for (int j = x; j < x + 3; j++) {
				if (!(i == y + 1 && j == x + 1))
					mat[i][j] = '*';
			}
		}
		return;
	}

	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (!(i == 1 && j == 1))
				f(len / 3, y + len / 3 * i, x + len / 3 * j);
		}
	}

}

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			mat[i][j] = ' ';
	}
	f(n, 0, 0);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cout << mat[i][j];
		cout << '\n';
	}
}