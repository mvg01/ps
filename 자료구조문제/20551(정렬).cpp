#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int arr[200001];
map<int, int>ma;
int n, m;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	for (int i = 0; i < n; i++) 
		ma.insert({ arr[i],i });
}

void solve() {
	int x;
	for (int i = 0; i < m; i++) {
		cin >> x;
		if (ma.find(x) == ma.end())
			cout << -1 << '\n';
		else
			cout << ma[x] << '\n';
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}