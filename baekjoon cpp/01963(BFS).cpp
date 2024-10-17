#include <bits/stdc++.h>
using namespace std;

int t, a, b, n = 10000;
int p[10001];
int visited[10001];

void prime() {
	for (int i = 2; i <= n; i++)
		p[i] = i;
	for (int i = 2; i <= n; i++) {
		if (p[i] == 0)
			continue;
		for (int j = i + i; j <= n; j += i)
			p[j] = 0;
	}
}

void init() {
	for (int i = 0; i < 10000; i++)
		visited[i] = 0;
}

int bfs(int a, int b) {
	queue<string>q;
	string s = to_string(a);
	q.push(s);
	visited[a] = 1;
	while (!q.empty()) {
		s = q.front();
		int e = stoi(s);
		int d = visited[e];
		if (e == b) 
			return d - 1;
		q.pop();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j <= 9; j++) {
				if (i == 0 && j == 0)
					continue;
				string temp = s;
				temp[i] = j + '0';
				int num = stoi(temp);
				if (p[num] != 0 && !visited[num]) {
					q.push(temp);
					visited[num] = d + 1;
				}
			}
		}
	}
	return -1;
}

void input() {
	prime();
	cin >> t;
	for (int i = 0; i < t; i++) {
		cin >> a >> b;
		int res = bfs(a, b);
		if (res != -1)
			cout << res<<'\n';
		else
			cout << "Impossible\n";
		init();
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}