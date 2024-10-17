#include <iostream>
#include <map>
using namespace std;

map<string, int> m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, r = 0;
	string x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (x == "ENTER") {
			m.clear();
		}
		else {
			if (m.find(x) == m.end()) {
				m.insert({ x,1 });
				r++;
			}
		}
	}
	cout << r;
}