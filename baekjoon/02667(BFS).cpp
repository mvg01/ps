#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int mat[26][26];
int visited[26][26];
int go[4][2] = { {-1,0},{0,1},{1,0},{0,-1} };
int apart[625] = { 0 };  //단지 수 담아놓을 배열

void bfs(int y, int x, int idx) {
	queue<pair<int, int>> q;
	q.push({ y,x });
	visited[y][x] = 1;
	apart[idx]++;

	while (!q.empty()) {
		int yy = q.front().first;
		int xx = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			if (!visited[yy + go[i][0]][xx + go[i][1]] && mat[yy + go[i][0]][xx + go[i][1]] == 1) {
				q.push({ yy + go[i][0], xx + go[i][1] });
				visited[yy + go[i][0]][xx + go[i][1]] = 1;
				apart[idx]++;
			}
		}
	}
}

int main()
{
	int n;
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < s.size(); j++)
			mat[i][j] = s[j] - '0';
	}
	int idx = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]&&mat[i][j]==1)
				bfs(i, j, idx++);
		}
	}

	sort(apart, apart + idx);
	cout << idx << '\n';
	for (int i = 0; i < idx; i++)
		cout << apart[i] << '\n';
}
