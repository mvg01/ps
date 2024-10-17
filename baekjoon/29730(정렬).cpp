#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

vector<string>v;
vector<string>ps;
string s;
bool com(string a, string b) {
	if (a.size() < b.size())
		return 1;
	else if (a.size() > b.size())
		return 0;
	else {
		if (a < b)
			return 1;
		else
			return 0;
	}
}

bool com2(string a, string b) {  //문제 번호가 낮은 순서대로
	int anum = stoi(a.substr(7, a.size() - 6));
	int bnum = stoi(b.substr(7, a.size() - 6));
	if (anum < bnum)
		return 1;
	else
		return 0;
}

int main()
{
	int n;
	cin >> n;
	getchar();
	for (int i = 0; i < n; i++) {
		getline(cin, s);
		bool brk = 0;
		if (s.substr(0, 7) == "boj.kr/") {
			for (int i = 7; i < s.size(); i++) {
				if (s[i] > '9' || s[i] < '0') { //백준 문제인지 알아야겠어
					brk = 1;
					break;
				}
			}
			if (!brk) {
				ps.push_back(s);
				continue;
			}
		}
		v.push_back(s);
	}
	sort(v.begin(), v.end(), com);
	sort(ps.begin(), ps.end(), com2);
	int vs = v.size();
	int pss = ps.size();
	for (int i = 0; i < vs; i++)
		cout << v[i] << '\n';
	for (int i = 0; i < pss; i++)
		cout << ps[i] << '\n';
}