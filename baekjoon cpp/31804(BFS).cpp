#include <bits/stdc++.h>
using namespace std;

int a, b;
bool vis[1000001][2];

void solve() {
    queue<tuple<int, int, int>>q;
    q.push({ a,0,0 });
    vis[a][0] = 1;
    while (q.size()) {
        auto [score, c, skill] = q.front();
        q.pop();
        if (score == b) {
            cout << c;
            return;
        }
        if (!vis[score + 1][skill]) {
            q.push({ score + 1,c + 1,skill });
            vis[score + 1][skill] = 1;
        }
        if (score * 2 <= b) {
            if (!vis[score * 2][skill]) {
                q.push({ score * 2,c + 1,skill });
                vis[score * 2][skill] = 1;
            }
        }
        if (!skill) {
            if (score * 10 <= b) {
                q.push({ score * 10,c + 1,1 });
                vis[score * 10][1] = 1;
            }
        }

    }
}

void input() {
    cin >> a >> b;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}