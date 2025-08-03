#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string>v;
string s;

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}
	sort(v.begin(), v.end());

	int res = n;
	for (int i = 0; i < n - 1; i++) {
		bool chk = 0;
		for (int j = 0; j < min(v[i].size(), v[i + 1].size()); j++) {
			if (v[i + 1][j] != v[i][j])
				chk = 1;
		}
		if (!chk)
			res--;
	}
	cout << res;
}