#include <iostream>
#include <algorithm>
using namespace std;

// 정렬하면 안된다.
int n, m, sum = 0;
int arr[100001];
int res = 1000000000;

void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
}

void solve() {
	
	int start = *max_element(arr, arr + n), end = sum, mid;
	while (start <= end) {
		mid = (start + end) / 2;
		int temp = 0;
		int cnt = 1;
		for (int i = 0; i < n; i++) {
			temp += arr[i];
			if (temp > mid) {
				temp = arr[i];
				cnt++;
			}
		}
		if (cnt <= m) {
			end = mid - 1;
			res = min(res, mid);
		}
		else
			start = mid + 1;
	}
	cout << res;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}