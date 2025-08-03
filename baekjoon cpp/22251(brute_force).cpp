#include <iostream>
#include <string>
using namespace std;

int n, k, p, res = 0;
string x;
int num[10][7] = {
	{1,1,1,0,1,1,1},
	{0,0,1,0,0,1,0},
	{1,0,1,1,1,0,1},
	{1,0,1,1,0,1,1},
	{0,1,1,1,0,1,0},
	{1,1,0,1,0,1,1},
	{1,1,0,1,1,1,1},
	{1,0,1,0,0,1,0},
	{1,1,1,1,1,1,1},
	{1,1,1,1,0,1,1},
};

void input() {
	cin >> n >> k >> p >> x;
}

void solve() {
	string str;
	for (int i = 0; i < k - x.length(); i++)
		str.push_back('0');
	str += x;
	for (int i = n; i >= 1; i--) {
		string temp = to_string(i);
		if (temp == x)
			continue;
		string z;
		for (int j = 0; j < k - temp.length(); j++)
			z.push_back('0');
		z += temp;

		int cnt = 0;
		for (int j = 0; j < k; j++) {
			int y = z[j] - '0';
			for (int l = 0; l < 7; l++) {
				if (num[y][l] != num[str[j]-'0'][l])
					cnt++;
			}
		}
		if (cnt <= p && cnt >= 1)
			res++;
	}
	cout << res;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	input();
	solve();
}