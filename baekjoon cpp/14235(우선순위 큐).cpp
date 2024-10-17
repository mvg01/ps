#include <iostream>
#include <queue>
#include <vector>
using namespace std;

priority_queue<int> q; //내림차순 우선순위 큐
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 0 && q.size() != 0) {
			cout << q.top() << '\n';
			q.pop();
		}
		else if (a == 0)
			cout << -1 << '\n';
		else {
			for (int j = 0; j < a; j++) {
				cin >> x;
				q.push(x);
			}
			
		}
	}
}