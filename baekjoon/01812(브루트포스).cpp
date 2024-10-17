#include <iostream>
using namespace std;

int n, arr[1000], res[1000];
int sum[1000] = { 0 };
void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum[i] += arr[i];
	}
}

void solve() {
	int idx = 0;
	bool chk;
	while (1) {
		chk = 0;
		res[0] = idx++;
		for (int i = 1; i < n; i++) 
			res[i] = arr[i - 1] - res[i - 1];

		for (int i = 1; i < n; i++) {
			if (arr[i-1] != res[i] + res[i - 1])
				chk = 1;
		}
		if (arr[n-1] != res[0] + res[n - 1])
			chk = 1;

		if (!chk)
			break;
	}
	
	for (int i = 0; i < n; i++) 
		cout << res[i] << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}