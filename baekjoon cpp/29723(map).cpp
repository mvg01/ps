#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;

map<string, int>ma;
vector<pair<int, string>>v;

bool com(pair<int, string>a, pair<int, string>b) {
	return a.first > b.first;
}

int main()
{	
	string s;
	int n, m, k, score;
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> s >> score;
		ma.insert({ s,score });
		v.push_back({ score,s });  //점수 내림차순 위한
	}
	sort(v.begin(), v.end(), com);

	int res_max = 0, res_min = 0;
	for (int i = 0; i < k; i++) {
		cin >> s;
		res_max += ma[s];
		res_min += ma[s];
		for (auto it = v.begin(); it != v.end(); ++it) {  //삭제
			if (it->second == s) {
				v.erase(it);
				break;
			}
		}
	}
	
	for (int i = 0; i < m-k; i++) {	
		res_max += v[i].first;
		res_min += v[v.size() - i - 1].first;
	}
	cout << res_min << ' ' << res_max;
}