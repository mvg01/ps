#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	vector <long long> v;
	int n, m, x, j;
	long long res = 0;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	//1000 log 1000 = 3000 * 15000 = 45,000,000
	for (int i = 0; i < m; i++) {
		sort(v.begin(), v.end());

		long long temp = v.at(0) + v.at(1);
		v.at(0) = temp; v.at(1) = temp;
	}

	for (int i = 0; i < n; i++)
		res += v.at(i);
	cout << res;
}