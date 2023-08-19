#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> v;
int main()
{
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end());

	if (n % 2)
		cout << v.at(n / 2);
	else
		cout << v.at(n / 2 - 1);
}