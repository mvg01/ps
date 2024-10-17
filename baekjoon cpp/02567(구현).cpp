#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool map[101][101] = { false, };
vector<pair<int, int>> v;

//동서남북이 3개가 true면 둘레 한 개 (-), 2개면 둘레 2개 (┐) 형태

int chk(int i, int j) {   
	int cnt = 4;
	if (map[i][j - 1] == true)
		cnt--;
	if (map[i - 1][j] == true)
		cnt--;
	if (map[i + 1][j] == true)
		cnt--;
	if (map[i][j + 1] == true)
		cnt--;
	return cnt;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b, res = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
		for (int k = b; k < b + 10; k++) {
			for (int j = a; j < a + 10; j++)
				map[j][k] = true;
		}
	}
	for (int i = 1; i <= 100; i++) {
		for (int j = 1; j <= 100; j++) {
			if (map[i][j] == true) {
				res += chk(i, j);
			}
		}
	}
	cout << res;
}