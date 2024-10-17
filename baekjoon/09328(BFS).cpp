#include <bits/stdc++.h>
using namespace std;

int t, h, w, res = 0;
int d[4][2] = { {1,0},{-1,0},{0,-1},{0,1} };
char mat[101][101];
bool visited[101][101];
bool k[27];
string key;
queue<pair<int, int>>q;
vector<pair<int, int>>door;  // 탐색 도중 문을 만나면 문 위치 저장

// 탐색 중, 열쇠를 발견 or 문을 발견하면 모든 문과 열쇠를 체크해본다. 문이 열린다면 해당위치로 탐색
void door_chk() {
    for (int i = 0; i < door.size(); i++) { 
        if (k[mat[door[i].first][door[i].second] + 32-'a'] && !visited[door[i].first][door[i].second]) {
            q.push({ door[i].first,door[i].second });
            visited[door[i].first][door[i].second] = 1;
        }
    }
}

void bfs() {
    while (q.size()) {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++) {
            int dy = yy + d[i][0];
            int dx = xx + d[i][1];
            if (dy >= h || dy < 0 || dx >= w || dx < 0)
                continue;
            if (visited[dy][dx])
                continue;
            if (mat[dy][dx] == '.') {
                q.push({ dy,dx });
                visited[dy][dx] = 1;
            }
            if (mat[dy][dx] >= 'a' && mat[dy][dx] <= 'z') {
                q.push({ dy,dx });
                visited[dy][dx] = 1;
                k[mat[dy][dx] - 'a'] = 1;
                door_chk();
            }
            if (mat[dy][dx] >= 'A' && mat[dy][dx] <= 'Z') {
                door.push_back({ dy,dx });
                door_chk();
            }
            if (mat[dy][dx] == '$') {
                res++;
                q.push({ dy,dx });
                visited[dy][dx] = 1;
            }
        }
    }
}

void find_key() {
    // 가장자리 탐색
    // 1. 벽은 탐색 X
    // 2. $ 는 res++, 탐색 큐에 추가
    // 3. 열쇠를 찾으면 열쇠배열에 체크 후 모든 문 확인
    // 4. 문을 찾으면 문 list에 추가 후 모든 문 재확인 -> 기존에 있던 열쇠가 새 문을 열수도 있다.
    // 5. 빈 공간은 일반 탐색
    for (int i = 0; i < h; i++) {
        if (i != 0 && i != h - 1) {
            if (mat[i][0] != '*') {
                if (mat[i][0] == '$') {
                    q.push({ i,0 });
                    res++;
                    visited[i][0] = 1;
                }
                else if (mat[i][0] >= 'a' && mat[i][0] <= 'z') {
                    q.push({ i,0 });
                    visited[i][0] = 1;
                    k[mat[i][0] - 'a'] = 1;
                    door_chk();
                }
                else if (mat[i][0] >= 'A' && mat[i][0] <= 'Z') {
                    door.push_back({ i,0 });
                    door_chk();
                }
                else {
                    q.push({ i,0 });
                    visited[i][0] = 1;
                }
            }
            if (mat[i][w - 1] != '*') {
                if (mat[i][w - 1] == '$') {
                    q.push({ i,w - 1 });
                    res++;
                    visited[i][w - 1] = 1;
                }
                else if (mat[i][w - 1] >= 'a' && mat[i][w - 1] <= 'z') {
                    q.push({ i,w - 1 });
                    visited[i][w - 1] = 1;
                    k[mat[i][w - 1] - 'a'] = 1;
                    door_chk();
                }
                else if (mat[i][w - 1] >= 'A' && mat[i][w - 1] <= 'Z') {
                    door.push_back({ i,w - 1 });
                    door_chk();
                }
                else {
                    q.push({ i,w - 1 });
                    visited[i][w - 1] = 1;
                }
            }
        }
        else {
            for (int j = 0; j < w; j++) {
                if (mat[i][j] != '*') {
                    if (mat[i][j] == '$') {
                        q.push({ i,j });
                        res++;
                        visited[i][j] = 1;
                    }
                    else if (mat[i][j] >= 'a' && mat[i][j] <= 'z') {
                        q.push({ i,j });
                        visited[i][j] = 1;
                        k[mat[i][j] - 'a'] = 1;
                        door_chk();
                    }
                    else if (mat[i][j] >= 'A' && mat[i][j] <= 'Z') {
                        door.push_back({ i,j });
                        door_chk();
                    }
                    else {
                        q.push({ i,j });
                        visited[i][j] = 1;
                    }
                }
            }
        }
    }
    bfs();
}

void solve() {
    if (key != "0") {
        for (int i = 0; i < key.length(); i++)
            k[key[i] - 'a'] = 1;
    }
    find_key();
    cout << res << "\n";
    door.clear();
    res = 0;
    for (int i = 0; i <= 26; i++)
        k[i] = 0;
    for (int i = 0; i < 101; i++) {
        for (int j = 0; j < 101; j++)
            visited[i][j] = 0;
    }
}

void input() {  
    cin >> t;
    while (t--) {
        cin >> h >> w;
        for (int i = 0; i < h; i++)
            cin >> mat[i];
        cin >> key;
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}