#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector <pair<int, int>> v;

int n;
int res = 0;
void bt(int idx) {
	if (idx == n) {
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (v[i].first <= 0)
				c++;
		}
		res = max(c, res);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (v[idx].first <= 0)   //손의 계란이 깨져있는 경우
			bt(idx + 1);
		else if (idx == i || v[i].first <= 0) //치려는 계란이 깨져있거나 손의 계란 인덱스인 경우
			continue;
		
		else {
			v[i].first -= v[idx].second;
			v[idx].first -= v[i].second;
			bt(idx + 1);
			v[i].first += v[idx].second;
			v[idx].first += v[i].second;
		}
	}
	//재귀가 이루어지지 않고 끝나는 경우 체크해야함
	int c = 0;
	for (int i = 0; i < n; i++) {
		if (v[i].first <= 0)
			c++;
	}
	res = max(c, res);
}

int main()
{
	int a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}

	bt(0);
	cout << res;
}