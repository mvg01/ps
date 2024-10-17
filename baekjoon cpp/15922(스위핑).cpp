#include <iostream>
#include <vector>
using namespace std;

vector<pair<int, int>>v;
int n;
long long res = 0;
void input() {
	int x, y;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		v.push_back({ x,y });
	}
}

void solve() {
	int start = v[0].first, end = v[0].second;
	for (int i = 1; i < n; i++) {
		// 1. v[i].x값이 end보다 크거나 같은 경우
		if (v[i].first >= end) {
			res += abs(end - start);
			start = v[i].first;
			end = v[i].second;
		}
		// 2. v[i].y값이 end보다 작은 경우
		else if (end < v[i].second)
			end = v[i].second;
	}
	cout << res + end - start;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}