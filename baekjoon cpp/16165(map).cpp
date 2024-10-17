#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, vector<string>> ma;
string group;
vector<string> gr_name;
string name;
vector<int> gr_num;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, m, num;
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> group;
		gr_name.push_back(group);
		cin >> num;
		gr_num.push_back(num);
		for (int j = 0; j < num; j++) {
			cin >> name;
			ma[group].push_back(name);
		}
		sort(ma[group].begin(), ma[group].end());
	}

	for (int i = 0; i < m; i++) {
		cin >> name;
		cin >> num;
		bool brk = 0;
		if (num) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < gr_num[j]; k++) {
					if (ma[gr_name[j]][k] == name) {
						cout << gr_name[j] << '\n';
						brk = 1;
						break;
					}
				}
				if (brk)
					break;
			}
		}
		else {
			for (int j = 0; j < n; j++) {
				if (gr_name[j] == name) {
					for (int k = 0; k < gr_num[j]; k++)
						cout << ma[gr_name[j]][k] << '\n';
					break;
				}
			}
		}
	}
}