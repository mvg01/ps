#include <iostream>
using namespace std;

int main()
{
	int t, n, m, r, c, s;
	cin >> t;
	while (t--) {
		int chk = 0;
		int rowchk = 0, colchk = 0;
		cin >> n >> m >> r >> c >> s;
		if (r - s <= 1) {
			chk++;
			rowchk++;
		}
		if (c - s <= 1) {
			chk++;
			colchk++;
		}

		if (chk == 2) {
			cout << "Tuzik\n";
			continue;
		}
		chk = 0;
	
		if (c + s >= m) {
			chk++;
			colchk++;
		}
		if (r + s >= n) {
			chk++;
			rowchk++;
		}

		if (chk != 2 && rowchk != 2 && colchk != 2)
			cout << "Barsik\n";
		else
			cout << "Tuzik\n";
	}
}