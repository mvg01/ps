#include <iostream>
#include <vector>
#include <cmath>
#include <string>
using namespace std;

int n;
int a[4] = { 2,3,5,7 };
int b[5] = { 1,3,5,7,9 };
string res;

int prime(string s) { 
	int num = stoi(s);
	for (int i = 2; i <= sqrt(num); i++) {
		if (num % i == 0)
			return 0;
	}
	return 1;
}

void bt(int cnt) {
	if (cnt == n) {
		cout << res << '\n';
		return;
	}
	for (int i = 0; i < 5; i++) {
		res[cnt] = b[i] + '0';
		if (!prime(res)) {  //소수가 아니면 다시 조합
			res[cnt] = 0;
			continue;
		}
		bt(cnt + 1); 
		res[cnt] = 0;
	}
}

int main()
{
	cin >> n;
	res.resize(n);

	for (int i = 0; i < 4; i++) {
		res[0] = a[i] + '0';
		bt(1);
	}
}