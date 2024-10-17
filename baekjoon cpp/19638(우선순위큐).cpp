#include <iostream>
#include <queue>
using namespace std;

priority_queue<int>q;
int n, h, t;

void input() {
	int x;
	cin >> n >> h >> t;
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
	}
}

void solve() {
	int res = 0;
	for (int i = 0; i < t; i++) {
		int temp = q.top();
		if (temp >= h) // 뿅망치 사용횟수
			res++;

		q.pop();
		if (temp != 1)
			temp /= 2;
		q.push(temp);
	}
	
	for (int i = 0; i < n; i++) {
		if (q.top() >= h) {
			cout << "NO\n" << q.top();
			return;
		}
		q.pop();
	}
	cout << "YES\n" << res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}