#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;

int t, w, h, r;
int s_x, s_y; //상근이의 시작 위치
vector<string>mat;
vector<pair<int, int>>fire;  //초기 불 위치
int dy[4] = { -1,0,0,1 };
int dx[4] = { 0,1,-1,0 };
int visited[1001][1001];
int fire_visited[1001][1001];

void init() {
    for (int i = 0; i <= h; i++) {
        for (int j = 0; j <= w; j++) {
            visited[i][j] = 0;
            fire_visited[i][j] = INF;
        }
    }
}

int bfs() {
    queue<pair<int, int>>q;
    q.push({ s_y,s_x });
    visited[s_y][s_x] = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        int d = visited[y][x];
 
        q.pop();
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (yy == -1 || yy == h || xx == -1 || xx == w) 
                return d;
            if (visited[yy][xx])
                continue;
            if (mat[yy][xx] == '.' && fire_visited[yy][xx] > d + 1) {
                q.push({ yy,xx });
                visited[yy][xx] = d + 1;
            }
        }
    }
    return -1;
}

void bfs_fire() {
    queue<pair<int, int>>q;
    for (int i = 0; i < fire.size(); i++) {
        q.push({ fire[i].first,fire[i].second });
        fire_visited[fire[i].first][fire[i].second] = 1;
    }
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        int d = fire_visited[y][x];
        q.pop();
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (yy >= h || yy < 0 || xx >= w || xx < 0)
                continue;
            if (fire_visited[yy][xx]!=INF)
                continue;
            if (mat[yy][xx]!='#') {
                q.push({ yy,xx });
                fire_visited[yy][xx] = d + 1;
            }
        }
    }
}

void input() {
    cin >> t;
}

void solve() {
    while (t--) {
        string s;
        r = 0;
        cin >> w >> h;
        for (int i = 0; i < h; i++) {
            cin >> s;
            mat.push_back(s);
            for (int j = 0; j < w; j++) {
                if (s[j] == '@') {
                    s_y = i;
                    s_x = j;
                }
                else if (s[j] == '*')
                    fire.push_back({ i,j });
            }
        }
        init();
        bfs_fire();
        r = bfs();
        if (r != -1)
            cout << r << '\n';
        else
            cout << "IMPOSSIBLE\n";
        mat.clear();
        fire.clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}