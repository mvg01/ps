#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct classroom {
	int start;
	int end;
	classroom(int s, int e) {
		start = s;
		end = e;
	}
	bool operator < (const classroom a) const {
		return this->end > a.end;
	}
};
vector <pair<int, int>> v;
priority_queue<classroom> q;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, a, b;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b;
		v.push_back({ a,b });
	}
	sort(v.begin(), v.end());

	int res = 1;
	for (int i = 0; i < n; i++) {
		classroom temp(v[i].first, v[i].second);
		if (q.empty())
			q.push(temp);
		else if (q.top().end > temp.start) {
			q.push(temp);
			res++;
		}
		else if (q.top().end <= temp.start) {
			q.pop();
			q.push(temp);
		}
	}
	cout << res;
}