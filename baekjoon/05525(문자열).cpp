#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n, m, res = 0, chk = 1, j;
	string s;
	cin >> n >> m >> s;
	
	for (int i = 0; i < m; i++) {
		chk = 1;
		if (s[i] == 'I') {
			for (j = i + 1; j < m; j++) {
				if (chk % 2) {
					if (s[j] == 'O')
						chk++;
					else 
						break;
					
				}
				else {
					if (s[j] == 'I')
						chk++;
					else 
						break;
					
				}
			}

			if (n * 2 + 1 <= chk) {
				while (n * 2 + 1 <= chk) {
					res++;
					chk -= 2;
				}
			}
			i = j - 1;
		}
	}
	cout << res;
}