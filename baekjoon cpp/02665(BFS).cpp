#include <bits/stdc++.h>
#define INF 99999999
using namespace std;

// 0-1 BFS 최단경로 문제
// Queue 대신 Deque을 사용
// 이 문제에선 가중치가 0인 정점은 push_back로 (최대한 안쓴다는 전략), 가중치가 1이면 push_front로 
// O(V+E) 

int n;
char mat[51][51];
int visited[51][51];
int d[4][2] = { {0,-1},{0,1},{1,0},{-1,0} };

void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
}

void solve() {
    deque < tuple <int, int, int >> dq;
    dq.push_back({ 0,0,0 });
    visited[0][0] = 1;
    while (!dq.empty()) {
        int y = get<0>(dq.front());
        int x = get<1>(dq.front());
        int p = get<2>(dq.front());
        dq.pop_front();
        if (y == n - 1 && x == n - 1) {
            cout << p;
            return;
        }
        for (int i = 0; i < 4; i++) {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= n || xx < 0)
                continue;
            if (visited[yy][xx])
                continue;
            if (mat[yy][xx] == '1') {
                dq.push_front({ yy,xx,p });
                visited[yy][xx] = 1;
            }
            else {
                dq.push_back({ yy,xx,p + 1 });
                visited[yy][xx] = 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}