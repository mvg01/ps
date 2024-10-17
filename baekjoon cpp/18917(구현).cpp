#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

vector<int>a;
unordered_map<int, int>map;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int m, s, x;
	long long sum = 0;
	long long exor = 0;
	cin >> m;
	map.insert({ 0,1 });
	for (int i = 0; i < m; i++) {
		cin >> s;
		switch (s) {
		case 1:
			cin >> x;
			if (map.find(x) == map.end())
				map.insert({ x,1 });
			else
				map[x]++;
			sum += x;
			exor ^= x;
			break;
		case 2:
			cin >> x;
			map[x]--;
			sum -= x;
			exor ^= x;
			break;
		case 3:
			cout << sum << '\n';
			break;
		case 4:
			cout << exor << '\n';
			break;
		}
	}
}