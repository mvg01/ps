#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

struct classroom {
	int start;
	int end;
	classroom(int s, int e) {
		start = s;
		end = e;
	}
	bool operator<(const classroom a)const {  //먼저 끝나는 강의가 우선순위가 높다.
		return this->end > a.end;
	}
};

priority_queue<classroom> q;
vector<pair<int, int>> v;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, a, b, c;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		v.push_back({ b,c });
	}
	sort(v.begin(), v.end()); //강의 시작 시간 순 오름차순

	int res = 1;
	for (int i = 0; i < n; i++) {
		classroom temp(v[i].first, v[i].second);
		if (q.empty())   
			q.push(temp);

		//수업이 끝난 후 재 활용이 가능할 강의실에 대해서
		else if (q.top().end <= temp.start) { //가장 빨리끝나는 수업시간이 새 강의가 시작할 시간보다 작거나 같다면
			q.pop();
			q.push(temp);
		}

		else if (q.top().end > temp.start) {
			res++;
			q.push(temp);
		}

		//밑의 출력은 가장 빨리 끝날 수업에 대한 시간
		//cout << q.top().start << ' ' << q.top().end << '\n';
	}
	cout << res;
}