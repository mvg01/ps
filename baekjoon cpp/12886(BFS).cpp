#include <bits/stdc++.h>
using namespace std;

int a, b, c;
int visited[1001][1001][6]; // a,b,c 3개의 숫자 조합 6개
void input() {
    cin >> a >> b >> c;
}

void solve() {
    queue<tuple<int, int, int>>q;
    q.push({ a,b,c });
    visited[a][b][0] = 1;
    visited[b][a][1] = 1;
    visited[a][c][2] = 1;
    visited[c][a][3] = 1;
    visited[b][c][4] = 1;
    visited[c][b][5] = 1;
    while (!q.empty()) {
        int a1 = get<0>(q.front());
        int b1 = get<1>(q.front());
        int c1 = get<2>(q.front());
        q.pop();
        if (a1 == b1 && b1 == c1) {
            cout << 1;
            return;
        }
        if (a1 > b1) {
            if (b1 > 500)
                continue;
            if (!visited[a1 - b1][b1 * 2][0]) {
                q.push({ a1 - b1,b1 * 2,c1 });
                visited[a1 - b1][b1 * 2][0] = 1;
            }
        }
        if (a1 < b1) {
            if (a1 > 500)
                continue;
            if (!visited[a1 * 2][b1 - a1][1]) {
                q.push({ a1 * 2,b1 - a1,c1 });
                visited[a1 * 2][b1 - a1][1] = 1;
            }
        }
        if (a1 > c1) {
            if (c1 > 500)
                continue;
            if (!visited[a1 - c1][c1 * 2][2]) {
                q.push({ a1 - c1,b1,c1 * 2 });
                visited[a1 - c1][c1 * 2][2] = 1;
            }
        }
        if (a1 < c1) {
            if (a1 > 500)
                continue;
            if (!visited[a1 * 2][c1 - a1][3]) {
                q.push({ a1 * 2,b1,c1 - a1 });
                visited[a1 * 2][c1 - a1][3] = 1;
            }
        }
        if (b1 > c1) {
            if (c1 > 500)
                continue;
            if (!visited[b1 - c1][c1 * 2][4]) {
                q.push({ a1,b1 - c1,c1 * 2 });
                visited[b1 - c1][c1 * 2][4] = 1;
            }
        }
        if (b1 < c1) {
            if (b1 > 500)
                continue;
            if (!visited[b1 * 2][c1 - b1][5]) {
                q.push({ a1,b1 * 2,c1 - b1 });
                visited[b1 * 2][c1 - b1][5] = 1;
            }
        }
    }
    cout << 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}