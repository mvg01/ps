#include <iostream>
using namespace std;

int parent[1000001];

void init() {
	for (int i = 0; i < 1000001; i++)
		parent[i] = i;
}

int get_parent(int x) {
	if (x == parent[x])
		return x;
	else
		return parent[x] = get_parent(parent[x]);
}

void set_union(int a, int b) {
	int a1 = get_parent(a);
	int b1 = get_parent(b);
	if (a1 > b1)
		parent[a1] = b1;
	else
		parent[b1] = a1;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, k, m, a, b;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		init();
		cin >> n >> k;
		for (int j = 0; j < k; j++) {
			cin >> a >> b;
			set_union(a, b);
		}
		cin >> m;
		cout << "Scenario " << i << ":\n";
		for (int j = 0; j < m; j++) {
			cin >> a >> b;
			if (get_parent(a) == get_parent(b))
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
		cout << '\n';
	}
}