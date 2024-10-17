#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct compare {
	bool operator()(int a, int b) {
		if (abs(a) != abs(b))
			return abs(a) > abs(b);
		else    //절댓값이 같다면 작은 순으로
			return a > b;
	}
};

priority_queue<int, vector<int>, compare> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == 0) {
			if (q.empty()) 
				cout << 0 << '\n';
			
			else {
				cout << q.top() << '\n';
				q.pop();
			}
		}

		else 
			q.push(x);
	}
}