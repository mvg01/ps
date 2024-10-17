#include <iostream>
#include <map>
#include <string>
using namespace std;

map <string, int, greater<string>> m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string name, s;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> s;
		if (s == "leave")
			m.erase(name);
		else
			m.insert({ name, i });
	}
	for (auto iter = m.begin(); iter != m.end(); iter++) {
		cout << iter->first << '\n';
	}
}