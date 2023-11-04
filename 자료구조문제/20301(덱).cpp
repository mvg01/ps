#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

deque<int>d;
int main()
{
	int n, k, m;
	cin >> n >> k >> m;
	for (int i = 1; i <= n; i++)
		d.push_back(i);

	int cnt = 0;
	bool reverse = 0;  //순열이 반전될 때 true
	while (!d.empty()) {
		if (!reverse) {
			for (int i = 0; i < k; i++) {
				int temp = d.front();
				d.pop_front();
				d.push_back(temp);
			}
			cout << d.back() << '\n';
			d.pop_back();
		}

		else {
			for (int i = 0; i < k; i++) {
				int temp = d.back();
				d.pop_back();
				d.push_front(temp);
			}
			cout << d.front() << '\n';
			d.pop_front();
		}
		cnt++;
		if (cnt % m == 0)
			reverse = !reverse;
	}
}