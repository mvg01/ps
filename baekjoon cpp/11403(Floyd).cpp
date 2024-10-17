#include <iostream>
using namespace std;

int mat[101][101];
int main()
{
	int n, t;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			mat[i][j] = 999999999;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> t;
			if (t == 1) {
				mat[i][j] = 1;
			}
		}
	}

	for (int k = 0; k < n; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] != 999999999)
				cout << 1 << ' ';
			else 
				cout << 0 << ' ';
		}
		cout << '\n';
	}
}