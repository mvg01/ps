#include <iostream>
#include <map>
#include <vector>
using namespace std;

int n, k;
map<pair<int, int>, bool>m;
vector<pair<int, int>>v;  //다바바 담아둘 벡터
int main()
{
	int y, x, cnt = 0;
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		cin >> y >> x;
		m[{y, x}] = true;  //다바바 위치 접근 불가
		v.push_back({ y,x });
	}

	for (int i = 0; i < k; i++) {
		y = v[i].first;
		x = v[i].second;
		if (x + 2 <= n && m[{y, x + 2}] == false) {
			m[{y, x + 2}] = true;
			cnt++;
		}
		if (y + 2 <= n && m[{y + 2, x}] == false) {
			m[{y + 2, x}] = true;
			cnt++;
		}
		if (x - 2 >= 1 && m[{y, x - 2}] == false) {
			m[{y, x - 2}] = true;
			cnt++;
		}
		if (y - 2 >= 1 && m[{y - 2, x}] == false) {
			m[{y - 2, x}] = true;
			cnt++;
		}
	}
	cout << cnt;
}