#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//C++ binary_search 로 구현
//이 문제 맵으로도 구현 가능하다. 대신 시간이 더 걸리던데
//이유:https://www.acmicpc.net/board/view/57406
int arr[1000001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, m, x;
	cin >> t;
	while (t--) {
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		sort(arr, arr + n);
		cin >> m;
		for (int i = 0; i < m; i++) {
			cin >> x;

			if (binary_search(arr, arr + n, x))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}
}