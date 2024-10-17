#include <iostream>
#include <queue>
using namespace std;

int k, n, t, a[200001];
long long res = 0;
priority_queue<int>q1;  //상어가 당장 먹을 수 있는 상어들(max heap)
priority_queue<int, vector<int>, greater<int>>q2;  //상어가 당장 먹을 수 없는 상어들(min heap)

void input() {
	cin >> n >> k >> t;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (t > a[i])
			q1.push(a[i]);
		else
			q2.push(a[i]);
	}
}

void solve() {
	res = t;
	for (int i = 0; i < k; i++) {
		while (!q2.empty()) {
			if (res > q2.top()) {
				q1.push(q2.top());
				q2.pop();
			}
			else
				break;
		}
		if (q1.empty())
			break;
		res += q1.top();
		q1.pop();
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}