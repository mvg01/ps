#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>
using namespace std;

int n, num = 9, res = 0;
vector<string>v;
map<char, bool>m;
int alpha[26] = { 0 };
int sum[26] = { 0 }; 
char mat[10][8];
int ten[8] = { 10000000,1000000,100000,10000,1000,100,10,1 };

bool com(pair<int, char>a, pair<int, char>b) {
	return a.first > b.first;
}

void input() {
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
		for (int j = 0; j < s.length(); j++) {
			m.insert({ s[j],1 });
		}
	}
}

void solve() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 8; j++)
			mat[i][j] = '0';
	}
	for (int i = 0; i < n; i++) {
		int len = v[i].length();
		for (int j = 0; j < len; j++)
			mat[i][8 - len + j] = v[i][j];
	}
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[j][i] != '0') {
				sum[mat[j][i]-'A'] += ten[i];
			}
		}
	}
	vector<pair<int,char>>vv;
	for (int i = 0; i < 26; i++) {
		if (sum[i] != 0) 
			vv.push_back({ sum[i],i + 'A' });
	}
	sort(vv.begin(), vv.end(), com);
	for (int i = 0; i < vv.size(); i++) {
		alpha[vv[i].second-'A'] = num;
		num--;
	}
	for (int i = 0; i < n; i++) {
		string temp;
		for (int j = 0; j < v[i].size(); j++)
			temp.push_back(alpha[v[i][j] - 'A'] + '0');
		res += stoi(temp);
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}