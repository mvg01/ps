#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
map<string, int> m;

int comp(pair<string, int>& a, pair<string, int>& b) {
	if (a.second != b.second) 
		return a.second > b.second;

	else if (a.second == b.second) {

		if (a.first.size() != b.first.size())
			return a.first.size() > b.first.size();

		else
			return a.first < b.first; // 사전 순 아스키 값 작으면 앞으로 
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int N, M;
	vector<string> list;
	string str;
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> str;
		list.push_back(str);
		if (str.size() >= M) {
			if (m.count(str) == 0)
				m.insert({ str,1 });
			else
				m[str]++;
		}
	}
	//for (auto iter = m.begin(); iter != m.end(); iter++)
	//	cout << iter->first << ' ' << iter->second << '\n';

	vector<pair<string, int>> vv(m.begin(), m.end());
	sort(vv.begin(), vv.end(), comp);

	int len = vv.size();
	for (int i = 0; i < len; i++)
		cout << vv[i].first << '\n';
}