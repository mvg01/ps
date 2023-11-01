#include <iostream>
#include <algorithm>
using namespace std;
int mat1[101][101];
int mat2[101][101];
int n, m, r, t;

int main()
{
	cin >> n >> m >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> mat1[i][j];
	}
	int chk = 0;    //돌리는 횟수 카운트 mat2인지 mat1인지 확인용도
	int n2 = n / 2, m2 = m / 2, temp;

	for (int y = 0; y < r; y++) {
		cin >> t;

		switch (t) {
		case 1:
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (chk % 2 == 0)
						mat2[i][j] = mat1[n - 1 - i][j];

					else
						mat1[i][j] = mat2[n - 1 - i][j];
				}
			}
			break;

		case 2:
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					if (chk % 2 == 0)
						mat2[i][j] = mat1[i][m - j - 1];
					else
						mat1[i][j] = mat2[i][m - j - 1];
				}
			}
			break;

		case 3:
			if (chk % 2 == 0) {
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						mat2[i][j] = mat1[n - j - 1][i];
					}
				}
			}
			else {
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						mat1[i][j] = mat2[n - j - 1][i];
					}
				}
			}
			temp = n;
			n = m;
			m = temp;
			n2 = n / 2;
			m2 = m / 2;
			break;

		case 4:
			if (chk % 2 == 0) {
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						mat2[i][j] = mat1[j][m - i - 1];
					}
				}
			}
			else {
				for (int i = 0; i < m; i++) {
					for (int j = 0; j < n; j++) {
						mat1[i][j] = mat2[j][m - i - 1];
					}
				}
			}
			temp = n;
			n = m;
			m = temp;
			n2 = n / 2;
			m2 = m / 2;
			break;

		case 5:
			if (chk % 2 == 0) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (i < n2 && j < m2) //1번그룹
							mat2[i][j] = mat1[i + n2][j];
						else if (i < n2 && j >= m2)  //2번그룹
							mat2[i][j] = mat1[i][j - m2];
						else if (i >= n2 && j >= m2)  //3번그룹
							mat2[i][j] = mat1[i - n2][j];
						else if (i >= n2 && j < m2)  //4번그룹
							mat2[i][j] = mat1[i][j + m2];
					}
				}
			}
			else {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (i < n2 && j < m2) //1번그룹
							mat1[i][j] = mat2[i + n2][j];
						else if (i < n2 && j >= m2)  //2번그룹
							mat1[i][j] = mat2[i][j - m2];
						else if (i >= n2 && j >= m2)  //3번그룹
							mat1[i][j] = mat2[i - n2][j];
						else if (i >= n2 && j < m2)  //4번그룹
							mat1[i][j] = mat2[i][j + m2];
					}
				}
			}
			break;
		case 6:
			if (chk % 2 == 0) {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (i < n2 && j < m2) //1번그룹
							mat2[i][j] = mat1[i][j + m2];
						else if (i < n2 && j >= m2)  //2번그룹
							mat2[i][j] = mat1[i + n2][j];
						else if (i >= n2 && j >= m2)  //3번그룹
							mat2[i][j] = mat1[i][j - m2];
						else if (i >= n2 && j < m2)  //4번그룹
							mat2[i][j] = mat1[i - n2][j];
					}
				}
			}
			else {
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						if (i < n2 && j < m2) //1번그룹
							mat1[i][j] = mat2[i][j + m2];
						else if (i < n2 && j >= m2)  //2번그룹
							mat1[i][j] = mat2[i + n2][j];
						else if (i >= n2 && j >= m2)  //3번그룹
							mat1[i][j] = mat2[i][j - m2];
						else if (i >= n2 && j < m2)  //4번그룹
							mat1[i][j] = mat2[i - n2][j];
					}
				}
			}
			break;
		}
		chk++;
		
	}

	if (chk % 2 == 0) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << mat1[i][j] << ' ';
			cout << '\n';
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++)
				cout << mat2[i][j] << ' ';
			cout << '\n';
		}
	}
}
	