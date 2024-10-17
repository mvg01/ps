#include <iostream>
#include <vector>
using namespace std;

int n, k;
int idx = 0;
int kk = 0;
int res[15] = { 0 };
vector<string> v;
void bt(int start, int sum) {
	if (sum == n) {
		kk++;
		if (kk == k) {
			for (int i = 1; i <= n; i++) {
				if (res[i] != 0) {
					if (i != n)
						cout << res[i] << '+';
					else
						cout << res[i];
				}
			}
		}
		return;
	}

	for (int i = 1; i <= 3; i++) {
		if (sum <= n) {
			res[sum + i] = i;
			bt(i, sum + i);
			res[sum + i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	bt(0, 0);
	if (kk < k)
		cout << -1;
}