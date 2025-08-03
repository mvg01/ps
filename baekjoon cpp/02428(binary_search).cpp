#include <iostream>
#include <algorithm>
using namespace std;

long long n, res = 0;
double arr[100001];

void input() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
}

long long bs(int idx) {
	int left = idx + 1, right = n - 1, mid;
	while (left <= right) {
		mid = (left + right) / 2;
		if (arr[idx] >= arr[mid] * 0.9) 
			left = mid + 1;
		else
			right = mid - 1;
	}

	if (mid == idx + 1) {  //만약 mid가 idx 바로 오른쪽 값이었다면 따로 비교
		if (arr[idx] >= arr[mid] * 0.9)
			return 1;
		else
			return 0;
	}
	mid = (right + left) / 2;
	return mid - idx;
}

void solve() {
	sort(arr, arr + n);
	for (int i = 0; i < n - 1; i++) {
		res += bs(i);
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