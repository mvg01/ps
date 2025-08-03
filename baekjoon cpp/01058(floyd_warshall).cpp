#include <iostream>
#define INF 99999999
using namespace std;

int mat[51][51];
int n;

void input() {
	char c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			if (i == j)
				mat[i][j] = 0;
			else if (c == 'Y')
				mat[i][j] = 1;
			else
				mat[i][j] = INF;
		}
	}
}
void floyd() {
	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}
}

void solve() {
	floyd();
	int res = 0;
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		for (int j = 0; j < n; j++) {
			if (mat[i][j] <= 2 && i != j)  //거리가 2보다 작거나 같은게 2 친구. 자신은 해당하지 않는다.
				cnt++;
		}
		res = max(res, cnt);
	}
	cout << res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}