#include <iostream>
#include <string>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	int n, star;
	string p;
    string front, back;
	cin >> n;
	cin >> p;
	for (int i = 0; ; i++) {
		if (p.at(i) != '*')
			front.push_back(p.at(i));
		else {
			star = i;
			break;
		}
	}
	for (int i = star + 1; i < p.size(); i++)
		back.push_back(p.at(i));

	while (n--) {
		string t;
		cin >> t;

		bool chk = 1;
		int tsize = t.size();
		if (tsize < p.size()-1) {  //예외처리
			cout << "NE" << '\n';
			continue;
		}

		for (int i = 0; i < front.size(); i++) {
			if (front.at(i) != t.at(i)) {
				chk = false;
				break;
			}
		}
		int idx = 0;
		for (int i = tsize - back.size(); i < tsize; i++) {
			if (back.at(idx++) != t.at(i)) {
				chk = false;
				break;
			}
		}
		if (chk)
			cout << "DA" << '\n';
		else
			cout << "NE" << '\n';
	}
}