#include <iostream>
#include <vector>
using namespace std;

typedef struct {
	int s;
	int b;
}in;

int n;
int res = 1000000000;
int chk[10] = { 0 };
in list[10];

void bt(int k, int cnt, int bit, int sour) {

	if (cnt == k) {
		if (res > abs(bit - sour))
			res = abs(bit - sour);
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!chk[i]) {
			chk[i] = 1;
			bt(k, cnt + 1, bit + list[i].b, sour * list[i].s);
			chk[i] = 0;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;
	for (int i = 0; i < n; i++) 
		cin >> list[i].s >> list[i].b;

	for (int i = 1; i <= n; i++) {
		bt(i, 0, 0, 1);
	}
	cout << res;
}