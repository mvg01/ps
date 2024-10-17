#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>v;
vector<int>res;
int main()
{
	int n, m, p, l, x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> p >> l;
		if (l > p) {
			res.push_back(1);
			for (int j = 0; j < p; j++) //1마일리지로 수강하는 거 확정이지만 값을 입력 받긴 해야함!
				cin >> x;
			continue;
		}

		v.clear();
		for (int j = 0; j < p; j++) {
			cin >> x;
			v.push_back(x);
		}
		sort(v.begin(), v.end());
		int idx = 0;
		for (int j = 0; j < p - l; j++) 
			idx++;

		res.push_back(v[idx]);
	}

	sort(res.begin(), res.end());
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (m - res[i] >= 0) {
			c++;
			m -= res[i];
		}
		else
			break;
	}
	cout << c;
}