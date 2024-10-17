#include <iostream>
#include <algorithm>
using namespace std;
int n;
int a[1025][1025];
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cin >> a[i][j];
	}
}

int solve(int y, int x, int p) {
	if (p == 1)
		return a[y][x];

	int res[4];
	res[0] = solve(y, x, p / 2);
	res[1] = solve(y, x + p / 2, p / 2);
	res[2] = solve(y + p / 2, x, p / 2);
	res[3] = solve(y + p / 2, x + p / 2, p / 2);
	sort(res, res + 4);
	return res[1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	if (n == 1)
		cout << a[0][0];
	else 
		cout<<solve(0, 0, n);
}