#include <iostream>
using namespace std;

int v[1000001] = { 0 };
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, x;
	cin >> n;
	int res = n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		v[x]++;
		if (v[x + 1] > 0) {
			res--;
			v[x + 1]--;
		}
	}
	cout << res;
}