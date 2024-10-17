#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

unordered_map<string, int> m;
vector<string> v;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, t;
	string x;
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> x;
		m.insert({ x,i + 1 });
		v.push_back(x);
	}
	char find[32];
	for (int i = 0; i < t; i++) {
		cin >> find;
		if (find[0] >= 65)
			cout << m[find] << '\n';
		else {
			cout << v.at(atoi(find) - 1) << '\n';
		}
	}
}