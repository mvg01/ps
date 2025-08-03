#include <iostream>
#include <algorithm>
using namespace std;

int n;
int mat[1025][1025];
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) 
			cin >> mat[i][j];
	}
}

int solve(int y,int x,int depth) {
	if (depth == 1)
		return mat[y][x];
	int temp[4];
	temp[0]=solve(y, x, depth / 2);
	temp[1]=solve(y, x + depth / 2, depth / 2);
	temp[2]=solve(y + depth / 2, x, depth / 2);
	temp[3]=solve(y + depth / 2, x + depth / 2, depth / 2);
	sort(temp, temp + 4);
	return temp[2];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	cout << solve(0, 0, n);
}