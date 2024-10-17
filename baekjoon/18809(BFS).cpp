#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int n, m, g, r, res = 0;
int mat[51][51];
int dy[4] = { 0,1,-1,0 };
int dx[4] = { 1,0,0,-1 };
bool chk[11];
vector<pair<int, int>>v;
vector<pair<int, int>>re;
vector<pair<int, int>>gr;
typedef struct t {
    int color;
    int time;
}t;
t visited[51][51];

void input() {
    cin >> n >> m >> g >> r;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> mat[i][j];
            if (mat[i][j] == 2)
                v.push_back({ i,j });
        }
    }
}

int bfs() {
    int cnt = 0;  //꽃의 개수
    queue <pair<int, int>>q;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (mat[i][j] == 0) {  // 호수
                visited[i][j].time = 10000;
                visited[i][j].color = 0;
            }
            else {
                visited[i][j].time = 0;
                visited[i][j].color = 0;  // 0은 정해지지 않음, 1은 red, 2는 green, 3은 꽃으로
            }
        }
    }
    for (int i = 0; i < re.size(); i++) {  // 초기 빨간색 배양액
        q.push({ re[i].first,re[i].second});
        visited[re[i].first][re[i].second].time = 1;
        visited[re[i].first][re[i].second].color = 1;
    }
    for (int i = 0; i < gr.size(); i++) {  // 초기 초록색 배양액
        q.push({ gr[i].first,gr[i].second});
        visited[gr[i].first][gr[i].second].time = 1;
        visited[gr[i].first][gr[i].second].color = 2;
    }
    while (!q.empty()) {
        int yy = q.front().first;
        int xx = q.front().second;
        int clr = visited[yy][xx].color;
        int dis = visited[yy][xx].time;
        q.pop();
        for (int i = 0; i < 4; i++) {
            if (visited[yy][xx].color == 3)  // 이미 전의 자리가 꽃이 핀 자리라면 더이상 배양 X
                break;
            int ry = yy + dy[i];
            int rx = xx + dx[i];
            int nextcolor = visited[ry][rx].color;
            if (ry >= n || ry < 0 || rx >= m || rx < 0)
                continue;
            if (visited[ry][rx].time == 10000 || nextcolor == 3)  // 호수거나 꽃
                continue;

            if (nextcolor == 0) {  // 아직 배양액이 오지 못함
                visited[ry][rx].time = dis + 1;
                visited[ry][rx].color = clr;
                q.push({ ry,rx });
            }
            else if ((clr == 1 && nextcolor == 2) || (clr == 2 && nextcolor == 1)) {
                if (dis + 1 == visited[ry][rx].time) {
                    visited[ry][rx].time = 10000;
                    visited[ry][rx].color = 3;
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

void solve(int idx, int red, int green) {
    if (red == r && green == g) {
        res = max(res, bfs());
        return;
    }
    if (idx >= v.size())  // 모든 배양액 위치를 다 확인한 경우
        return;

    if (red < r) {
        re.push_back({ v[idx].first, v[idx].second });
        solve(idx + 1, red + 1, green);
        re.pop_back();
    }
    if (green < g) {
        gr.push_back({ v[idx].first, v[idx].second });
        solve(idx + 1, red, green + 1);
        gr.pop_back();
    }
    solve(idx + 1, red, green);  // 현재 위치 배양액 패스
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve(0, 0, 0);
    cout << res;
}