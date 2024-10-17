#include <iostream>
#include <vector>
using namespace std;

int n;
int a[8];
int v[8] = { 0 };
void bt(int cnt) {
	if (cnt == n) {
		for (int i = 0; i < n; i++)
			cout << a[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 0; i < n; i++) {
		if (!v[i]) {
			a[cnt] = i + 1;
			v[i] = 1;
			bt(cnt + 1);
			v[i] = 0;
		}
	}
}

int main()
{
	cin >> n;
	bt(0);
}