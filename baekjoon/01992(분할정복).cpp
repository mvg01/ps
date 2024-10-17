#include <iostream>
using namespace std;

int n;
string res;
char mat[65][65];

void func(int p, int y, int x) {
	if (p == 1) {
		res += mat[y][x];
		return;
	}
	char point = mat[y][x];
	bool brk = 0;
	for (int i = y; i < y + p; i++) {
		for (int j = x; j < x + p; j++) {
			if (point != mat[i][j]) {
				brk = 1;
				break;
			}
		}
		if (brk)
			break;
	}

	if (brk) {
		res += "(";
		func(p / 2, y, x);
		func(p / 2, y, p / 2 + x);
		func(p / 2, p / 2 + y, x);
		func(p / 2, p / 2 + y, p / 2 + x);
		res += ")";
	}
	else 
		res += point;
	
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> mat[i];
	func(n, 0, 0);
	cout << res;
}