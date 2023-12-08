#include <iostream>
#define INF 999999999
using namespace std;

int n, m;
int mat[101][101];

void init() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j)
				mat[i][j] = INF;
			else
				mat[i][j] = 0;
		}
	}
}

void input() {
	int a, b;
	cin >> n >> m;
	init();
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		mat[a][b] = 1;
		mat[b][a] = 1;
	}
}

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}
}

void solve() {
	floyd();
	int dis = INF, res1, res2;
	for (int i = 1; i <= n; i++) {

		int temp[101] = { 0 };
		for (int k = 1; k <= n; k++) {  //i:첫번째 치킨집
			temp[k] = mat[i][k] * 2;
		}
		temp[i] = 0; //첫번째 치킨집
		for (int j = 1; j <= n; j++) {  //j:두번째 치킨집
			if (i == j)   //중복 치킨집
				continue;
			temp[j] = 0;  //두번째 치킨집
			
			int sum = 0;
			for (int k = 1; k <= n; k++) {
				temp[k] = min(mat[i][k] * 2, mat[j][k] * 2);
				sum += temp[k];
			}
			if (dis > sum) {
				res1 = i;
				res2 = j;
				dis = sum;
			}
		}
	}
	cout << res1 << ' ' << res2 << ' ' << dis;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}