#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
vector<int> x;
bool c(int i, int j) {
	return i > j;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, k, z, res = 0;
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> z;
		x.push_back(z);
	}
	sort(x.begin(), x.end());

	for (int i = 0; i < n - 1; i++)
		v.push_back(x[i + 1] - x[i]);
	sort(v.begin(), v.end());

	for (int i = 0; i < n - k; i++)
		res += v[i];
	
	cout << res;
}