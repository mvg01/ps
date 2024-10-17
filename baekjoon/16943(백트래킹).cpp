#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string a;
vector<int>v;
int main()
{
	int b, len, c = -1;
	cin >> a >> b;
	len = a.size();
	for (int i = 0; i < a.size(); i++)
		v.push_back(a[i]);
	
	sort(v.begin(), v.end());

	do {
		if (v[0] == '0') //c는 0으로 시작 X
			continue;
		int num = 0, ten = 1;
		for (int i = len-1; i >=0; i--) {
			num += (v[i] - '0') * ten;
			ten *= 10;
		}

		if (num < b) {
			c = max(c, num);
		}
	} while (next_permutation(v.begin(), v.end()));

	if (c == -1)
		cout << -1;
	else
		cout << c;
}