#include <iostream>
#include <vector>
#define INF 100000000
using namespace std;

int res = INF;
void dfs(long a, long b,int idx) {
	if (a == b) {
		res = min(res, idx);
		return;
	}

	if (a > b) 
		return;
	
	dfs(a * 2, b, idx + 1);
	dfs(a * 10 + 1, b, idx + 1);
}

int main()
{
	long a, b;
	cin >> a >> b;
	dfs(a, b, 1);
	if (res == INF)
		cout << -1;
	else
		cout << res;
}