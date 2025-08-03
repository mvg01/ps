#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<long, vector<long>, greater<long>>q;
int n;
long res = 0;
void input() {
	int x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		q.push(x);
	}
}

void solve() {
	for (int i = 0; i < n - 1; i++) {
		long a = q.top();
		q.pop();
		long b = q.top();
		q.pop();
		q.push(a + b);
		res += a + b;
	} 
	cout << res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}