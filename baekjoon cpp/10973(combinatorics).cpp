#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int>v;
vector<int>a;
int main()
{
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		a.push_back(x);
		v.push_back(x);
	}
	prev_permutation(v.begin(), v.end());
	bool chk = 0;
	
	for (int i = 0; i < n - 1; i++) {
		if (a[i] + 1 == a[i + 1])
			chk = 0;
		else {
			chk = 1;
			break;
		}
	}

	if (!chk)
		cout << -1;
	else {
		for (int i = 0; i < n; i++)
			cout << v[i] << ' ';
	}
}