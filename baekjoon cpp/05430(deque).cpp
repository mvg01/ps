#include <iostream>
#include <string>
#include <deque>
#include <algorithm>
using namespace std;
string p, x;
deque<int> d;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int t, n, len;
	cin >> t;
	while (t--) {
		cin >> p;
		cin >> n;
		cin >> x;
		len = x.size();
		bool reversechk = 0;  //0일때 원래 덱 유지
		bool chk = 0;
		int temp = 0;
		string num;
		if (n != 0) {
			for (int i = 1; i < len; i++) {
				if (x.at(i) != ',' && x.at(i) != ']')
					num.push_back(x.at(i));
				else
				{
					reverse(num.begin(), num.end());
					int ten = 1;
					for (int j = 0; j < num.size(); j++) {
						temp += (num[j] - '0') * ten;
						ten *= 10;
					}
					d.push_back(temp);
					num.clear();
					temp = 0;
				}
			}
		}
		int psize = p.size();
		for (int i = 0; i < psize; i++)
		{
			if (p.at(i) == 'R') {
				reversechk = !reversechk;
			}
			else if (p.at(i) == 'D') {
				if (!d.empty()) {
					if (!reversechk)
						d.pop_front();
					else
						d.pop_back();
				}
				else {
					cout << "error" << '\n';
					chk = 1;  //에러면 출력 X
					break;
				}
			}
		}
		int dsize = d.size();
		if (!chk) {
			cout << '[';
			if (d.size() > 0) {
				if (!reversechk) {
					for (int i = 0; i < dsize - 1; i++)
						cout << d.at(i) << ',';
					cout << d.back() << ']' << '\n';
				}
				else {
					for (int i = dsize - 1; i >= 1; i--)
						cout << d.at(i) << ',';
					cout << d.front() << ']' << '\n';
				}
			}
			else
				cout << ']' << '\n';
		}
		d.clear();
	}
}