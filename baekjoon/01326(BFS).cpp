#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int n;
int arr[10001];
int visited[10001] = { 0 };
int a, b, res = 100000;

void bfs(int p) {
	queue<pair<int, int>>q;
	q.push({ p,0 });
	visited[p] = 1;
	while (!q.empty()) {
		int d = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (d == b - 1) {
			res = cnt;
			break;
		}

		int jump = arr[d];  //점프 가능한 배수
		for (int i = d + jump; i < n; i += jump) {  //앞으로 점프
			if (!visited[i]) {
				q.push({ i,cnt + 1 });
				visited[i] = 1;
			}
		}
		for (int i = d - jump; i >= 0; i -= jump) {  //뒤로 점프
			if (!visited[i]) {
				q.push({ i,cnt + 1 });
				visited[i] = 1;
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	cin >> a >> b;
	bfs(a - 1);
	if (res != 100000)
		cout << res;
	else
		cout << -1;
}