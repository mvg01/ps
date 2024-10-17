#include <iostream>
#include <queue>
#include <vector>
#include <tuple>
using namespace std;

int w, h, n, cnt = 0;
int mat[51][51];
int visited[51][51];
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
queue<tuple<int, int, int>>q;

void input() {
    string s;
    int a, b;
    cin >> w >> h >> n;
    for (int i = 0; i < n; i++) {
        cin >> s >> a >> b;
        if (s == "redstone_block") {
            visited[b][a] = 1;
            q.push({ b,a,15 });
        }
        else if (s == "redstone_dust")
            mat[b][a] = 1;
        else {
            mat[b][a] = -1;
            cnt++;
        }
    }   
}

void solve() {
    int light = 0;
    while (!q.empty()) {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int e = get<2>(q.front());  // 전기신호
        q.pop();
        if (e == 0)
            continue;
        for (int i = 0; i < 4; i++) {
            int yy = y + dy[i];
            int xx = x + dx[i];
            if (yy >= h || yy < 0 || xx >= w || xx < 0)
                continue;
            if (visited[yy][xx])
                continue;
            if (mat[yy][xx] == -1) {  // 램프
                light++;
                visited[yy][xx] = 1;
            }
            if (mat[yy][xx] == 1) {  // 가루
                q.push({ yy,xx,e - 1 });
                visited[yy][xx] = 1;
            }
        }
    }
    if (cnt == light)
        cout << "success";
    else
        cout << "failed";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}