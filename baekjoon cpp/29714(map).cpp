#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int>m;
vector<int>a;

int main()
{
	int n, q, a, b, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		if (m.find(x) == m.end())
			m[x] = 1;
		else
			m[x]++;
	}
	cin >> q;
	for (int i = 0; i < q; i++) {
		bool chk = 0;
		vector<int>a;
		int an, bn;
		cin >> an;
		for (int j = 0; j < an; j++) {
			cin >> x;
			a.push_back(x);  //만약 아이스크림이 없다면 map을 원상태로 돌려놔야함
			m[x]--;
			if (m[x] < 0) 
				chk = 1;
		}
		cin >> bn;
		for (int j = 0; j < bn; j++) {
			cin >> x;
			if (!chk)  //a의 과정에서 아이스크림이 부족하지 않았다면
				m[x]++;
		}

		if (chk) {  //a의 과정에서 아이스크림이 부족했었다. -> map 원상 복귀
			for (int j = 0; j < an; j++) 
				m[a[j]]++;
		}

	}
	int sum = 0;
	int si = m.size();
	for (auto iter = m.begin(); iter != m.end(); iter++) 
		sum += iter->second;
	
	cout << sum << '\n';

	for (auto iter = m.begin(); iter != m.end(); iter++) {
		for (int i = 0; i < iter->second; i++) {
			cout << iter->first << ' ';
		}
	}
}