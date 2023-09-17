#include <iostream>
using namespace std;

int s[12][12];
int visited[12][12];
int chk[12];
int res;

void bt(int cnt, int score) {
	if (cnt == 11) {
		res = max(res, score);
		return;
	}
	for (int i = 0; i < 11; i++) {
		if (visited[cnt][i] == -1&&!chk[i]) {
			visited[cnt][i] = 1;
			chk[i] = 1;  //선발 명단 번호
			bt(cnt + 1, score + s[cnt][i]);
			visited[cnt][i] = -1;
			chk[i] = 0;
		}
	}
}

int main()
{
	int c;
	cin >> c;
	while (c--) {
		res = 0;
		for (int i = 0; i < 11; i++) {
			chk[i] = 0;
			for (int j = 0; j < 11; j++) {
				cin >> s[i][j];
				if (s[i][j] != 0)
					visited[i][j] = -1;  //조합을 만들 수 있는 경우
				else
					visited[i][j] = 0;
			}
		}
		bt(0, 0);
		cout << res << '\n';
	}
}