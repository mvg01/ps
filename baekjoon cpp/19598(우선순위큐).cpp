#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, res = 100000;
vector<pair<int, int>>v;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;  //first원소 기준 오름차순 정렬

bool com(pair<int, int>a, pair<int, int> b) {  //시작시간이 작을수록, 끝나는 시간이 작을수록 기준
	if (a.second < b.second)
		return true;
	else if (a.second > b.second)
		return false;
	else {
		if (a.first < b.first)
			return true;
		else return false;
	}
}

void input() {
	int s, e;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> e;
		v.push_back({ e,s });
	}
	sort(v.begin(), v.end(), com);
}

void solve() {
	int idx = 1;
	for (int i = 0; i < n; i++) {
		if (q.empty()) {
			q.push(v[i]);
			continue;
		}
		
		if (q.top().first <= v[i].second) {
			q.push(v[i]);
			q.pop();
		}
		else {
			idx++;
			q.push(v[i]);
		}
	}
	cout << idx;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}