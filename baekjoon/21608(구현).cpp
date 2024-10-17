#include <iostream>
#include <vector>
using namespace std;

int n;
int stu[401][4];
int mat[21][21];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,-1,1 };

vector<int>v;

void init() {
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			mat[i][j] = 0;
		}
	}
}

void next_step(int num) {
	int emptyseat = 0, emx = 0, emy = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (mat[i][j] != 0)
				continue;

			int empty = 0;
			for (int k = 0; k < 4; k++) {
				if (i + dy[k] > n || i + dy[k] < 1 || j + dx[k] > n || j + dx[k] < 1)
					continue;

				if (mat[i + dy[k]][j + dx[k]] == 0) 
					empty++;
			}
			if (empty > emptyseat) {
				emptyseat = empty;
				emx = j;
				emy = i;
			}
		}
	}
	if (emy == 0 && emx == 0) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (mat[i][j] == 0) {
					mat[i][j] = num;
					return;
				}
			}
		}
	}
	else {
		mat[emy][emx] = num;
	}
}

void find_seat(int num) {
	vector<pair<int, int>> likelist;
	int likemax = 0, likex = 0, likey = 0;  //주변에 좋아하는 학생의 수, 그 곳 자리 좌표
	bool go_next_step = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			if (mat[i][j] != 0)
				continue;

			int like = 0;
			for (int k = 0; k < 4; k++) {
				if (i + dy[k] > n || i + dy[k] < 1 || j + dx[k] > n || j + dx[k] < 1)
					continue;

				if (mat[i + dy[k]][j + dx[k]] != 0) {
					for (int l = 0; l < 4; l++) {
						if (mat[i + dy[k]][j + dx[k]] == stu[num][l]) {
							like++;
						}
					}
				}
			}
			
			if (like != 0 && like == likemax) {  // 좋아하는 사람 인접한게 2개 이상
				go_next_step = 1;
				likelist.push_back({ i,j });
			}
			
			if (like > likemax) {
				likemax = like;
				likex = j;
				likey = i;
				go_next_step = 0;
				likelist.clear(); 
				likelist.push_back({ i,j });
			}
		}
	}
	if (likey == 0 && likex == 0) //maybe 처음의 경우
		next_step(num);
	else if (go_next_step == 0)  //좋아하는 사람 인접한 자리 많은게 딱 1개
		mat[likey][likex] = num;
	else if (go_next_step) {     //좋아하는 사람 인접한 자리가 많은게 여러개일떄
		int emptymax = 0, emy = 0, emx = 0;
		for (int i = 0; i < (int)likelist.size(); i++) {

			if (mat[likelist[i].first][likelist[i].second] != 0)
				continue;
			
			int temp = 0;
			for (int k = 0; k < 4; k++) {
				if (likelist[i].first + dy[k] > n || likelist[i].first + dy[k] < 1 || likelist[i].second + dx[k] > n || likelist[i].second + dx[k] < 1)
					continue;
				if (mat[likelist[i].first + dy[k]][likelist[i].second + dx[k]] == 0)
					temp++;
			}

			if (temp > emptymax) {
				emptymax = temp;
				emy = likelist[i].first;
				emx = likelist[i].second;
			}
		}

		if (emy == 0 && emx == 0) {
			for (int i = 0; i < (int)likelist.size(); i++) {

				if (mat[likelist[i].first][likelist[i].second] != 0)
					continue;
				else {
					mat[likelist[i].first][likelist[i].second] = num;
					break;
				}
			}
		}
		else 
			mat[emy][emx] = num;
	}
}

int score_sum() {
	int res = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {

			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				if (i + dy[k] > n || i + dy[k] < 1 || j + dx[k] > n || j + dx[k] < 1)
					continue;
				for (int l = 0; l < 4; l++) {
					if (mat[i + dy[k]][j + dx[k]] == stu[mat[i][j]][l])
						cnt++;
				}
			}

			if (cnt == 1)
				res++;
			else if (cnt == 2)
				res += 10;
			else if (cnt == 3)
				res += 100;
			else if (cnt == 4)
				res += 1000;
		}
	}
	return res;
}

int main()
{
	int student, like;
	cin >> n;
	for (int i = 0; i < n * n; i++) {
		cin >> student;
		v.push_back(student);
		for (int j = 0; j < 4; j++) {
			cin >> like;
			stu[student][j] = like;
		}
	}
	init();

	for (int i = 0; i < n * n; i++) {
		find_seat(v[i]);
	}
	cout << score_sum();
}
