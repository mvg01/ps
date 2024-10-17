#include <iostream>
#include <deque>
using namespace std;

deque <int>d;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x, cnt = 0;
	cin >> n;
	while (1) {
		cin >> x;
		if (x == -1)
			break;

		if (x != 0 && cnt < n) {
			d.push_back(x);
			cnt++;
		}
		else if (x == 0) {
			d.pop_front();
			cnt--;
		}
	}
	if (d.empty())
		cout << "empty";
	else {
		for (auto iter = d.begin(); iter != d.end(); iter++)
			cout << *iter << ' ';
	}
}