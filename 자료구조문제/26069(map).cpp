#include <iostream>
#include <map>
using namespace std;

map<string, bool> m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string x, y;
	int n, r = 0;
	cin >> n;
	m.insert({ "ChongChong",true });
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		m.insert({ x,0 });
		if (m[x] == true || m[y] == true) {
			m[x] = true;
			m[y] = true;
		}
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == true)
			r++;
	}
	cout << r;
}