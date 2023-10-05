#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, int>m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a == 1) {
			cin >> b >> c;
			m.insert({ c,b });
		}
		else if (a == 2) {
			cin >> b;
			cout << m[b] << '\n';
		}
	}
}