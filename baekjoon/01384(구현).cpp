#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
	int n, idx = 1;
	while (1) {
		cin >> n;
		if (n == 0)
			break;
		vector<string> v;
		char mat[21][21];
		v.resize(n);

		for (int i = 0; i < n; i++) {
			cin >> v[i];
			for (int j = 0; j < n - 1; j++) {
				cin >> mat[i][j];
			}
		}

		bool chk = 0;
		cout << "Group " << idx++ << '\n';
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (mat[i][j] == 'N') {
					cout << v[(i - j + n - 1) % n] << " was nasty about " << v[i] << '\n';
					chk = 1;
				}
			}
		}
		if (!chk)
			cout << "Nobody was nasty\n";
		cout << '\n';
	}
}