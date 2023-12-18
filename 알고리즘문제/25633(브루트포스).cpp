#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[1001];
int res[1001];

void input() {
	int x;
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> arr[i];
	for (int j = 0; j < n; j++)
		res[j] = 1;
}

void solve() {
	for (int i = 0; i < n; i++) {
		int temp[1001];
		for (int j = 0; j < n; j++)
			temp[j] = arr[j];

		for (int j = i + 1; j < n; j++) {
			if (temp[i] >= temp[j]) {
				res[i]++;
				temp[i] += temp[j];
			}
		}
	}
	int r = *max_element(res, res + n);
	cout << r;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}