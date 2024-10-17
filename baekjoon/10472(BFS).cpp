#include <iostream>
#include <queue>
#include <set>
using namespace std;

int p, res = 0;
string s;
set<string>se;
vector<vector<int>>v = {
	{0,1,3},{0,1,2,4},{1,2,5},{0,3,4,6},{1,3,4,5,7},{2,4,5,8},{3,6,7},{4,6,7,8},{5,7,8}
};

void bfs() {
	queue<pair<string, int>>q;
	q.push({ "000000000",1 });
	se.insert("000000000");
	while (!q.empty()) {
		string str = q.front().first;
		int cnt = q.front().second;
		q.pop();
		for (int i = 0; i < 9; i++) {
			string temp = str;
			for (int j = 0; j < v[i].size(); j++) {
				if (temp[v[i][j]] == '0')
					temp[v[i][j]] = '1';
				else
					temp[v[i][j]] = '0';
			}
			if (temp == s) {
				res = cnt;
				return;
			}
			if (se.find(temp) == se.end()) {
				se.insert(temp);
				q.push({ temp,cnt + 1 });
			}
		}
	}
}

void input() {
	char k;
	cin >> p;
	while (p--) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				cin >> k;
				if (k == '*')
					s += "1";
				else
					s += "0";
			}
		}
		if (s == "000000000")
			cout << "0\n";
		else {
			bfs();
			cout << res << '\n';
		}
		s.clear();
		se.clear();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
}