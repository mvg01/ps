#include <iostream>
#include <map>
#include <cmath>
using namespace std;

//비트마스킹 문제 비트연산자를 활용해봄.. 정해코드 보는게 나을듯
//가운데 출력문 주석 풀면 직관적으로 볼 수 있음

map<int, bool>ma;
int train[100001] = { 0 };
int seat[100001][22];

int main()
{
	int n, m, a, b, c;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= 21; j++)
			seat[i][j] = 0;
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b;  //명령의 종류, 기차
		if (a < 3) {
			cin >> c;   //c번 자리에
			int sum = (int)pow(2, c - 1);
			if (a == 1 && seat[b][c] == 0) {
				train[b] += sum;
				seat[b][c] = 1;
			}
			else if (a == 2 && seat[b][c] == 1) {
				train[b] -= sum;
				seat[b][c] = 0;
			}
		}
		if (a == 3) {
			train[b] = train[b] << 1;
			if (train[b] >= 1048576)  //2^20
				train[b] %= 1048576;
			for (int j = 20; j >= 1; j--)
				seat[b][j] = seat[b][j - 1];
			
		}
		if (a == 4) {
			if (train[b] == 1)
				train[b] = 0;
			train[b] = train[b] >> 1;
			for (int j = 1; j <= 20; j++)
				seat[b][j] = seat[b][j + 1];
		}

		/*for (int j = 1; j <= 20; j++)
			cout << seat[b][j];

		cout<<' '<< train[b];
		cout << '\n';*/

	}
	int res = 0;
	for (int i = 1; i <= n; i++) {
		if (ma.find(train[i]) == ma.end()) {
			ma.insert({ train[i],1 });
			res++;
		}
	}
	cout << res;
}

