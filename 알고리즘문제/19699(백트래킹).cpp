#include <iostream>
#include <queue>
using namespace std;

int n, m, arr[10];
bool visited[10];
int number = 10000;
int a[10001];
priority_queue<int, vector<int>, greater<int>>q;

void prime() {
	for (int i = 2; i <= number; i++)
		a[i] = i;
	for (int i = 2; i <= number; i++)
	{
		if (a[i] == 0)
			continue;
		for (int j = i + i; j <= number; j += i)
			a[j] = 0;
	}
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
}

void bt(int cnt, int sum, int s) {
	if (cnt == m) {
		if (a[sum] != 0) {
			q.push(sum);
			a[sum] = 0;  //이미 나온 소수
		}
		return;
	}
	for (int i = s; i < n; i++) {
		if (!visited[i]) {
			sum += arr[i];
			visited[i] = 1;
			bt(cnt + 1, sum, i + 1);
			visited[i] = 0;
			sum -= arr[i];
		}
	}
}

void solve() {
	prime();
	bt(0, 0, 0);
	if (q.empty()) 
		cout << -1;
	else {
		while (!q.empty()) {
			cout << q.top() << ' ';
			q.pop();
		}
	}
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}