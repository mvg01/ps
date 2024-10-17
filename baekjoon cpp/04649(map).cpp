#include <iostream>
#include <map>
using namespace std;

int main()
{
	int n;
	string s;
	while (1) {
		int res = 0;
		map<char, int> m;
		cin >> n;
		if (n == 0) break;
		cin >> s;
		int len = s.size();

		for (int i = 0; i < len; i++) {
			if (m.find(s[i]) != m.end())
				m.erase(s[i]);

			else {
				if (m.size() < n)
					m.insert({ s[i],1 });
				else
					res++;
			}
		}
		if (res == 0)
			cout << "All customers tanned successfully.\n";
		else
			cout << res / 2 << " customer(s) walked away.\n";
	}
}