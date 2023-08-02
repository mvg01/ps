#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
bool c(pair<string, int>& a, pair<string, int>& b) {
	return b.second > a.second;
}
map<string, int> m;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int k, l;
	string num;
	cin >> k >> l;
	for (int i = 0; i < l; i++) {
		cin >> num;
		if (m.find(num) != m.end())
			m[num] = i;
		else
			m.insert({ num,i });
	}
	//맵을 value값을 기준으로 정렬 -> vector로 변환 후 정렬
	vector<pair<string, int>> v(m.begin(), m.end());
	sort(v.begin(), v.end(), c);
	
	int cnt = 0;
	for (auto iter = v.begin(); iter != v.end(); iter++) {
		cout << iter->first << '\n';
		cnt++;
		if (cnt == k)
			break;
	}
}