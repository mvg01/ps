#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int n, m;
int ch = 0, h = 0;
int res = 1000000;
int selected[14];
vector<pair<int, int>>chicken; //전체 치킨집 배열
vector<pair<int, int>>home;
vector<pair<int, int>>open;  //살아남은 치킨집



int find_dis(int y, int x) {
	int mindis = 1000000;
	for (int i = 0; i < m; i++) {
		int yy = open.at(i).first;
		int xx = open.at(i).second;
		int sum = abs(yy - y) + abs(xx - x);
		mindis = min(mindis, sum);
	}
	return mindis;
}

void backTracking(int idx, int select) {
	if (select == m) {
		int dis_sum = 0;
		for (int i = 0; i < h; i++) {
			dis_sum += find_dis(home.at(i).first, home.at(i).second);
		}
		res = min(res, dis_sum);
		return;
	}
	for (int i = idx; i < ch; i++) {
		if (!selected[i]) {
			selected[i] = 1;
			int yy = chicken.at(i).first;
			int xx = chicken.at(i).second;
			open.push_back({ yy,xx });
			backTracking(i, select + 1);
			selected[i] = 0;
			open.pop_back();
		}
	}
}

int main()
{
	int x;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> x;
			if (x == 1) {
				h++;
				home.push_back({ i,j });
			}
			else if (x == 2) {
				ch++;
				chicken.push_back({ i,j });
			}
		}
	}

	backTracking(0,0);
	cout << res;
}