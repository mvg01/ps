#include <iostream>
#include <string>
#include <map>
using namespace std;

map<int, bool>m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int a, b, x;
	int r1 = 0, r2 = 0;
	cin >> a >> b;
	for (int i = 0; i < a; i++)
	{
		cin >> x;
		m.insert({ x, true });
	}
	for (int i = 0; i < b; i++)
	{
		cin >> x;
		if (m[x] == true) {
			r1++;
			r2++;
		}
	}
	cout << a - r1 + b - r2;
}