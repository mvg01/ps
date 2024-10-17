#include <iostream>
using namespace std;

int n, s;
int map[21][21];
int chk[21] = { 0 };
int res = 20000;

void bt(int cnt,int a) {  //a는 idx임

	/*for (int i = 1; i <= n; i++) {
		cout << chk[i] << ' ';
	}
	cout << '\n';*/

	if (cnt == n / 2) {
		int start = 0;
		int link = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (i != j) {
					if (chk[i] == 1 && chk[j] == 1)
						start += map[i][j];
					else if (chk[i] == 0 && chk[j] == 0)
						link += map[i][j];
				}
			}
		}
		if (res > abs(start - link))
			res = abs(start - link);

		return;
	}

	for (int i = a; i <= n; i++) {
		if (!chk[i]) {
			chk[i] = 1;
			bt(cnt + 1, i + 1);  //시간 단축을 위한 중복 제거 (i + 1)
			chk[i] = 0;
		}
	}

}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];
	}

	bt(0, 1);
	cout << res;
}