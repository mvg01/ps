#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

int problem[101][101];
typedef struct {
	int team_num;
	int score;
	int submit;
	int time;
}Team;

void init() {
	for (int i = 0; i < 101; i++) {
		for (int j = 0; j < 101; j++) {
			problem[i][j] = 0;
		}
	}
}

bool compare(Team a, Team b) {
	if (a.score == b.score) {
		if (a.submit == b.submit)
			return a.time < b.time;
		else
			return a.submit < b.submit;
	}
	else
		return a.score > b.score;
}

int main()
{
	int t, n, k, id, m;
	int a, b, c;
	cin >> t;
	while (t--) {
		cin >> n >> k >> id >> m;
		Team* t = new Team[n];
		for (int i = 0; i < n; i++) {
			t[i].team_num = i + 1;
			t[i].score = 0;
			t[i].submit = 0;
			t[i].time = 0;
		}
		init();
		for (int i = 0; i < m; i++) {
			cin >> a >> b >> c;  //각각 팀 ID, 문제번호, 점수
			if (problem[a - 1][b] == 0) {
				problem[a - 1][b] = c;
				t[a - 1].score += c;
			}
			else {
				if (problem[a - 1][b] < c) {
					t[a - 1].score += c - problem[a - 1][b];
					problem[a - 1][b] = c;
				}
			}
			t[a - 1].submit++;  //제출 횟수
			t[a - 1].time = i + 1;  //최종 제출 시간 체크용
		}

		sort(t, t + n, compare);
		for (int i = 0; i < n; i++) {
			if (t[i].team_num == id) {
				//cout << t[i].score << ' ';
				cout << i + 1 << '\n';
			}
		}
		delete[] t;
	}
}