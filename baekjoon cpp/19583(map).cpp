#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<string, bool>m;
string name, a, b, c;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	char x;
	int start_h = 0, start_m = 0, end_h = 0, end_m = 0, exit_h = 0, exit_m = 0;
	cin >> a >> b >> c;
	start_h += (a[0] - '0') * 10; start_h += a[1] - '0';
	start_m += (a[3] - '0') * 10; start_m += a[4] - '0';
	end_h += (b[0] - '0') * 10; end_h += b[1] - '0';
	end_m += (b[3] - '0') * 10; end_m += b[4] - '0';
	exit_h += (c[0] - '0') * 10; exit_h += c[1] - '0';
	exit_m += (c[3] - '0') * 10; exit_m += c[4] - '0';

	int res = 0;

	while (cin >> a >> name) {

		int enter_h = 0, enter_m = 0;
		enter_h += (a[0] - '0') * 10; enter_h += a[1] - '0';
		enter_m += (a[3] - '0') * 10; enter_m += a[4] - '0';


		if (enter_h < start_h) 
			m.insert({ name,1 });
		else if (enter_h == start_h && enter_m <= start_m)
			m.insert({ name,1 });

		else if (enter_h == end_h && enter_m >= end_m) {
			if (enter_h < exit_h) {
				if (m.find(name) != m.end()) {
					res++;
					m.erase(name);  //중복제거
				}
			}
			else if (enter_h == exit_h && enter_m <= exit_m) {
				if (m.find(name) != m.end()) {
					res++;
					m.erase(name);
				}
			}
		}
		else if (enter_h > end_h) {
			if (enter_h < exit_h) {
				if (m.find(name) != m.end()) {
					res++;
					m.erase(name);
				}
			}
			else if (enter_h == exit_h && enter_m <= exit_m) {
				if (m.find(name) != m.end()) {
					res++;
					m.erase(name);
				}
			}
		}
	}
	cout << res;
}