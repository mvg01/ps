#include <iostream>
#include <vector>
using namespace std;

vector<int>v[2001];
int sum[2001] = { 0 };
int main()
{
	int n, m, a, q;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> q;
			v[i].push_back(q);
		}
	}
	cin >> a;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) 
			sum[i] += v[j][i];
	}
	int res = 0;
	for (int i = 0; i < m - a + 1; i++) {
		int temp = 0;
		for (int j = i; j < i + a; j++) 
			temp += sum[j];
            
		res = max(temp, res);
	}
	cout << res;
}