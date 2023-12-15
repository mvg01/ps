#include <iostream>
#include <vector>
#include <map>
using namespace std;
int n;
string a, b;
bool chk = 0;
map<string, vector<string>>m;

void input() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a >> b;
		m[b].push_back(a);
	}
}

void find_child(string x, string find) {
	int size = m[x].size();
	for (int i = 0; i < size; i++) {
		if (m[x][i] == find) {
			chk = 1;
			return;
		}
		else
			find_child(m[x][i], find);
	}
}

void solve() {
	cin >> a >> b;
	find_child(a, b);
	find_child(b, a);
	if (chk)
		cout << 1;
	else
		cout << 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}