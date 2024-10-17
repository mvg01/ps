#include <iostream>
#include <vector>
using namespace std;

int mat[51][51];
int dir[8][2] = { {0,-1},{-1,-1},{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1} };
int chkdir[4][2] = { {-1,-1},{-1,1},{1,-1},{1,1} };
int prev_rain[51][51];
vector<pair<int, int>>v;  //구름 저장

int main()
{
	int n, m, d, s;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> mat[i][j];
			prev_rain[i][j] = 0;
		}
	}
	v.push_back({ n - 1,1 }); 
	v.push_back({ n - 1,2 }); 
	v.push_back({ n,1 });     
	v.push_back({ n,2 });  
	

	for (int i = 0; i < m; i++) {
		cin >> d >> s;  //d방향으로 s만큼 이동
		int size = v.size();
		for (int k = 0; k < s; k++) {
			for (int j = 0; j < size; j++) {
				v[j].first += dir[d - 1][0];
				v[j].second += dir[d - 1][1];

				if (v[j].first > n)
					v[j].first = 1;
				else if (v[j].first < 1)
					v[j].first = n;

				if (v[j].second > n)
					v[j].second = 1;
				else if (v[j].second < 1)
					v[j].second = n;
			}
		}

		for (int j = 0; j < size; j++) 
			prev_rain[v[j].first][v[j].second] = 1;  //비가 올 예정 (구름이 있는 곳 표시)
		


		for (int j = 0; j < size; j++) { 
			mat[v[j].first][v[j].second]++;   //구름 지역에 비가 내림
			for (int k = 0; k < 4; k++) {
				//대각선에 물이 있거나, 물이 0이지만 비가 올 예정인 지역
				if (v[j].first + chkdir[k][0] >= 1 && v[j].first + chkdir[k][0] <= n && v[j].second + chkdir[k][1] >= 1 && v[j].second + chkdir[k][1] <= n) {
					if (mat[v[j].first + chkdir[k][0]][v[j].second + chkdir[k][1]] > 0||prev_rain[v[j].first + chkdir[k][0]][v[j].second + chkdir[k][1]]==1) {  //대각선 체크
						mat[v[j].first][v[j].second]++;
					}
				}
			}
		}
		v.clear();  //구름 모두 제거

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (prev_rain[i][j] == 1) {
					prev_rain[i][j] = 0;  //원상 복구
					continue;
				}
				else if (mat[i][j] >= 2 && prev_rain[i][j] != 1) {
					v.push_back({ i,j });  //구름 생성
					mat[i][j] -= 2;        //구름 생기면 물의 양 2가 줄어듬

				}
			}
		}
	}

	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			res += mat[i][j];
		}
	}
	cout << res;
}