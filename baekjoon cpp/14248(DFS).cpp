#include <iostream>
using namespace std;

int n, s;
int a[100001];
bool chk[100001] = { 0 };
int res = 0;

void dfs(int s) {
	chk[s] = 1;
	res++;
	if (s - a[s] > 0 && s - a[s] <= n) {
		if (!chk[s - a[s]])
			dfs(s - a[s]);
	}
	if (s + a[s] > 0 && s + a[s] <= n) {
		if (!chk[s + a[s]])
			dfs(s + a[s]);
	}
}

int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++) 
		cin >> a[i];
	cin >> s;
	dfs(s);
	cout << res;
}