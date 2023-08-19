#include <iostream>
using namespace std;

int a[9];
int visited[9] = { 0 };
int temp[9] = { 0 };
int n;
int res = 0;

void bt(int cnt) {
	if (cnt == n) {
		int x = 0;
		for (int i = 0; i < cnt - 1; i++) 
			x += abs(temp[i] - temp[i + 1]);
		
		if (res < x)
			res = x;
		return;
	}
	
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			temp[cnt] = a[i];
			bt(cnt + 1);
			visited[i] = 0;
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		visited[i] = 1;
		temp[0] = a[i];
		bt(1);
		visited[i] = 0;
	}
	cout << res;
}