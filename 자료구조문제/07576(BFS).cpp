#include <iostream>
#include <tuple>  //3쌍의 값 tuplue 사용
#include <queue>
using namespace std;

int n, m;
int go[4][2] = { {-1,0},{0,1},{1,0},{0,-1} }; //북 동 남 서
int map[1001][1001];
int visited[1001][1001];
int good = 0;  //익은 토마토의 개수
int res = 0;

queue<tuple<int, int, int>>q;  //y, x, 몇 일째 인지
void bfs(int y, int x) {

	while (!q.empty()) {
		int yy = get<0>(q.front());
		int xx = get<1>(q.front());
		int day= get<2>(q.front());
		q.pop();
		if (res < day)  //모두 익은 토마토가 되기 전 필요한 day 일 수 있다.
			res = day;
        
		for (int i = 0; i < 4; i++) {
			if (yy + go[i][0] >= 0 && yy + go[i][0] < n && xx + go[i][1] >= 0 && xx + go[i][1] < m) { //범위 안에 있는지 확인
				if (!visited[yy + go[i][0]][xx + go[i][1]] && map[yy + go[i][0]][xx + go[i][1]] == 0) {
					map[yy + go[i][0]][xx + go[i][1]] = 1;
					q.push({ yy + go[i][0], xx + go[i][1],day + 1 });
					visited[yy + go[i][0]][xx + go[i][1]] = 1;
				}
			}
		}
	}
}

int main()
{
	cin >> m >> n;
	int minus = 0;  //빠져있는 토마토
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 0;
			cin >> map[i][j];
			if (map[i][j] == 1) {
				good++;
				q.push({ i,j ,0 });
				visited[i][j] = 1;
			}
			if (map[i][j] == -1)
				minus++;
		}
	}
	if (good == n * m - minus) {  //이미 다 익은 토마토 완성
		cout << 0;
		return 0;
	}

	bfs(0, 0);
	good = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 1)
				good++;
			
		}
	}
	if (good == n * m - minus)
		cout << res;
	else
		cout << -1;
}
