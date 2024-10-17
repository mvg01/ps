#include <iostream>
#include <string>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	int n;
	cin >> n;
	for (int i = 0; i < 2 * n - 1; i++) {
		cin >> s;
		if (m.find(s) != m.end()) {
			m[s]++;
		}
		else
			m.insert({ s, 1 });
	}
	for (auto iter=m.begin(); iter!=m.end(); iter++) {
		if (iter->second%2==1) {
			cout << iter->first;
			break;
		}
	}
}