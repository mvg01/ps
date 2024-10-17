#include <iostream>
#include <map>
using namespace std;

map<string, int>m;
int mat[6][6];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };

void dfs(int y, int x, int cnt, string temp) {
	if (cnt == 6) {
		if (m.find(temp) == m.end()) {
			m.insert({ temp,1 });
			//cout << temp << '\n';
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (y + dy[i] < 0 || y + dy[i] >= 5 || x + dx[i] < 0 || x + dx[i] >= 5) 
			continue;
		temp[cnt] = mat[y + dy[i]][x + dx[i]] + '0';
		dfs(y + dy[i], x + dx[i], cnt + 1, temp);
	}
}

int main() 
{
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			cin >> mat[i][j];
		}
	}
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {

			string s;
			s.resize(6);
			s[0] = mat[i][j] + '0';
			dfs(i, j, 1, s);
		}
	}
	cout << m.size();
}
