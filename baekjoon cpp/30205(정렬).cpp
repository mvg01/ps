#include <iostream>
#include <algorithm>
using namespace std;

int mat[501][501];  
int main() 
{
	int n, m;
	long long p;
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) 
			cin >> mat[i][j];

		sort(mat[i], mat[i] + m);
	}

	for (int i = 0; i < n; i++) {
		int item = 0;
		for (int j = 0; j < m; j++) {
			bool chk = 0;
			if (mat[i][j] == -1)
				item++;
			else {
				if (p >= mat[i][j])
					p += mat[i][j];
				else {  //현재 김병장이 이길 수 없음 -> 이길 때 까지 많이 약 빨기
					while (item) {
						p *= 2;
						item--;
						if (p >= mat[i][j]) {  //약 빨아서 이길 수 있어짐
							p += mat[i][j];
							chk = 1;
							break;
						}
					}
					if (!chk) {  //약 최대한 빨았지만 이길 수 없었다.
						cout << 0;
						return 0;
					}
				}	
			}
		}
		while (item) { //남은 약 다먹기
			p *= 2;
			item--;
		}
		//cout << p << '\n';
	}
	cout << 1;  //김병장 전역
}