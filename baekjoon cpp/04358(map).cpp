#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

map<string, double> m;
vector<string> v;
string s;
int main()
{
	int cnt = 0, all = 0;
	while (1) {
		getline(cin, s);
		if (s[0] == '\0')
			break;

		if (m.find(s) != m.end())
			m[s] += 1;
		else {
			m.insert({ s,1 });
			v.push_back(s);
			cnt++;
		}
		all++;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i<cnt; i++) {
		cout << v[i] << ' ';
		printf("%.4lf\n", m[v[i]] / all * 100);
	}
}