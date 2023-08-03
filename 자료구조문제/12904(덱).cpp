#include <iostream>
#include <string>
#include <deque>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	string s, t;
	deque<char>d;
	cin >> s >> t;
	int tsize = t.size();
	int ssize = s.size();
	for (int i = 0; i < tsize; i++) 
		d.push_back(t.at(i));

	while (tsize != ssize) {
		if (d.back() == 'A') {
			d.pop_back();
			tsize--;
		}
		else if (d.back() == 'B') {
			d.pop_back();
			tsize--;    //tsize가 곧 덱의 사이즈
			char temp;
			for (int i = 0; i < tsize/2; i++) {
				temp = d.at(i);
				d.at(i) = d.at(tsize - 1 - i);
				d.at(tsize - 1 - i) = temp;
			}
		}
	}
	t.clear();
	for (int i = 0; i < d.size(); i++) {
		t.push_back(d.at(i));
	}
	if (t == s)
		cout << 1;
	else
		cout << 0;
}