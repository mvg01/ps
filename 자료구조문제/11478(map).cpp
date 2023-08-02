#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

unordered_map<string, bool> m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s;
	cin >> s;
	int len = s.size();
	for (int i = 1; i <= len; i++)
	{
		for (int j = 0; j <= len - i; j++) {
			string x;
			x = s.substr(j, i); 
			if (m[x] != true) 
				m.insert({ x,true });
			//cout << x << '\n';
		}
	}
	cout << m.size();
}