#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
int main()
{
	int t;
	string s, temp;
	cin >> t;
	while (t--) {
		cin >> s;
		temp = s;
		sort(temp.begin(), temp.end());
		next_permutation(s.begin(), s.end());
		if (temp == s)
			cout << "BIGGEST\n";
		else
			cout << s << '\n';
	}
}