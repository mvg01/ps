#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>
#include <queue>
using namespace std;

priority_queue<int, vector<int>, greater<int>> q;  //오름차순
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> x;
		if (q.size() < n) //큐 사이즈를 n으로 제한
			q.push(x);
		else {
			if (q.top() < x) { 
				q.pop();
				q.push(x);
			}
		}
	}

	cout << q.top();
}