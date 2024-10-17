#include <iostream>
using namespace std;

char res[20];
int n;

void bt(int cnt, int sum, int idx) {
	if (cnt == n) {
		if (sum == 0) 
			printf("%s\n", res);

		return;
	}
	

	res[idx] = ' '; res[idx + 1] = cnt + 1 + '0';  //숫자 붙이기 먼저! ->아스키 순
	if (idx - 2 > 0) {
		if (res[idx - 2] == '+')
			bt(cnt + 1, sum + (10 * cnt + (cnt + 1)) - cnt, idx + 2);
		if (res[idx - 2] == '-')
			bt(cnt + 1, sum - (10 * cnt + (cnt + 1)) + cnt, idx + 2);
	}
	else
		bt(cnt + 1, 12, idx + 2);

	res[idx] = '+'; res[idx + 1] = cnt + 1 + '0';
	bt(cnt + 1, sum + cnt + 1, idx + 2);

	res[idx] = '-'; res[idx + 1] = cnt + 1 + '0';
	bt(cnt + 1, sum - (cnt + 1), idx + 2);
}

int main() 
{
	int t;
	cin >> t;
	while (t--) {
		for (int i = 0; i < 20; i++)
			res[i] = '\0';
		cin >> n;
		res[0] = '1';
		bt(1, 1, 1);
		printf("\n");
	}
}