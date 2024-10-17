#include <iostream>
#include <vector>
using namespace std;

int n;
int student = 0;
char mat[7][7];
int visited[7][7];
bool res = false;
vector<pair<int, int>>teacher;

void teacher_chk() {
	int s = student;  //학생 수 
	for (int i = 0; i < teacher.size(); i++) {
		int yy = teacher[i].first;
		int xx = teacher[i].second; 
		//y축 검사
		for (int j = yy - 1; j >= 0; j--) {
			if (mat[j][xx] == 'O')
				break;
			else if (mat[j][xx] == 'S')
				s--;
		}
		for (int j = yy + 1; j < n; j++) {
			if (mat[j][xx] == 'O')
				break;
			else if (mat[j][xx] == 'S')
				s--;
		}
		//x축 검사
		for (int j = xx - 1; j >= 0; j--) {
			if (mat[yy][j] == 'O')
				break;
			else if (mat[yy][j] == 'S')
				s--;
		}
		for (int j = xx + 1; j < n; j++) {
			if (mat[yy][j] == 'O')
				break;
			else if (mat[yy][j] == 'S')
				s--;
		}
	}
	if (s == student)  //학생이 모두 발견되지 않은 경우가 있다면
		res = true;
}

void select_obj(int y, int x, int cnt) { //장애물 조합 모든 경우의수 백트래킹
	if (cnt == 3) {
		teacher_chk();
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mat[i][j] == 'X' && !visited[i][j]) {
				visited[i][j] = 1;
				mat[i][j] = 'O';
				select_obj(i, j, cnt + 1);
				visited[i][j] = 0;
				mat[i][j] = 'X';
			}
		}
	}
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> mat[i][j];
			visited[i][j] = 0;
			if (mat[i][j] == 'T')
				teacher.push_back({ i,j });
			else if (mat[i][j] == 'S')
				student++;
		}
	}

	select_obj(0, 0, 0);
	if (res)
		cout << "YES";
	else
		cout << "NO";
	
}