#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> v;
int main()
{
	int n, res = 0, alpha[26] = { 0 };
	string s;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		v.push_back(s);
	}

	for (int i = 0; i < v.at(0).size(); i++)
		alpha[v.at(0)[i] - 'A']++;

	for (int i = 1; i < n; i++) {
		int temp[26] = { 0 };
		for (int j = 0; j < v.at(i).size(); j++)
			temp[v.at(i)[j] - 'A']++;

		int chk = 0;
		if (v.at(0).size() != v.at(i).size()) {
			for (int j = 0; j < 26; j++) {
				if (temp[j] != alpha[j]) {
					if (chk == 1)
						break;
					if (abs(temp[j] - alpha[j]) != 1)
						break;
					chk++;
				}

				if (j == 25) {
					res++;
					//cout << v[i] << '\n';
					chk = 0;
				}
			}
		}
		else {
			for (int j = 0; j < 26; j++) {
				if (temp[j] != alpha[j]) {
					if (chk == 2)
						break;

					if (abs(temp[j] - alpha[j]) != 1)
						break;
					chk++;
				}

				if (j == 25) {
					res++;
					//cout << v[i] << '\n';
				}
			}
		}
	}
	cout << res;
}