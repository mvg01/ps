#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

vector<int>v;
deque<pair<int, bool>>d;

int main() 
{
	int n, k, b, x, res = 100000;
	cin >> n >> k >> b;
	for (int i = 0; i < b; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());
	v.push_back(10000001);

	int cnt = 0, idx = 0;
	for (int i = 1; i <= k; i++) {
		if (i == v[idx]) {
			d.push_back({ i,1 });
			idx++;
			cnt++;  //망가진 신호등 개수
		}
		else
			d.push_back({ i,0 });
	}
	res = cnt;

	for (int i = k + 1; i <= n; i++) {
		if (d.front().second == 1) 
			cnt--;

		d.pop_front();
		if (i == v[idx]) {
			d.push_back({ i,1 });
			idx++;
			cnt++;  //망가진 신호등 개수
		}
		else
			d.push_back({ i,0 });

		res = min(res, cnt);
	}
	cout << res;
}