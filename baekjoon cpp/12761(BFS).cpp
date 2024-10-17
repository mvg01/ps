#include <iostream>
#include <queue>
using namespace std;

int a, b, n, m, res;
int visited[100001] = { 0 };
void input() {
	cin >> a >> b >> n >> m;
}

void bfs() {
	queue<int>q;
	q.push(n);
	visited[n] = 1;
	while (!q.empty()) {
		int p = q.front();
		int dis = visited[p];
		if (p == m) {
			res = dis - 1;
			break;
		}
		q.pop();
		if (p + 1 <= 100000) {
			if (!visited[p + 1]) {
				visited[p + 1] = dis + 1;
				q.push(p + 1);
			}
		}
		if (p - 1 >= 0) {
			if (!visited[p - 1]) {
				visited[p - 1] = dis + 1;
				q.push(p - 1);
			}
		}
		if (p + a <= 100000) {
			if (!visited[p + a]) {
				visited[p + a] = dis + 1;
				q.push(p + a);
			}
		}
		if (p + b <= 100000) {
			if (!visited[p + b]) {
				visited[p + b] = dis + 1;
				q.push(p + b);
			}
		}
		if (p - a >= 0) {
			if (!visited[p - a]) {
				visited[p - a] = dis + 1;
				q.push(p - a);
			}
		}
		if (p - b >= 0) {
			if (!visited[p - b]) {
				visited[p - b] = dis + 1;
				q.push(p - b);
			}
		}
		if (p * a <= 100000) {
			if (!visited[p * a]) {
				visited[p * a] = dis + 1;
				q.push(p * a);
			}
		}
		if (p * b <= 100000) {
			if (!visited[p * b]) {
				visited[p * b] = dis + 1;
				q.push(p * b);
			}
		}
	}
}

void solve() {
	bfs();
	cout << res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}