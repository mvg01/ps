#include <iostream>
#include <vector>
#include <map>
using namespace std;

int n, k;
int a[11];
int use[11];
int res = 0;
int visited[11] = { 0 };
map<string, bool> m;

void bt(int cnt) {
	if (cnt == k) {
		string s;
		for (int i = 0; i < k; i++) {
			if (use[i] > 9) {
				s.push_back(use[i] / 10 + '0');
				s.push_back(use[i] % 10 + '0');
			}
			else
				s.push_back(use[i] + '0');
		}
		//cout << s << '\n';
		if (m.find(s) == m.end()) {
			m.insert({ s,1 });
			res++;
		}
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			use[cnt] = a[i];
			bt(cnt + 1);
			visited[i] = 0;
		}
	}
}

int main()
{
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];

	bt(0);
	cout << res;
}