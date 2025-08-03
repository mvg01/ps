#include <iostream>
#include <vector>
using namespace std;

int chk[2000002] = { 0 };
vector<int>v;
int main()
{
	int n, x;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> x;
		chk[x] = 1;
		int size = v.size();
		for (int j = 0; j < size; j++) {
			chk[x + v[j]] = 1;
			v.push_back(x + v[j]);
		}
		v.push_back(x);
	}

	for (int i = 1; i <= 2000000; i++) {
		if (chk[i] == 0)
		{
			cout << i;
			return 0;
		}
	}
}