#include <bits/stdc++.h>
using namespace std;

int s;
bool visited[2002][2002];
void input() {
    cin >> s;
}

void solve() {
    queue<tuple<int, int, int>>q;
    q.push({ 1,0,0 });
    visited[0][1] = 1;
    while (!q.empty()) {
        int c = get<0>(q.front());
        int clip = get<1>(q.front());
        int t = get<2>(q.front());
        q.pop();
        if (c == s) {
            cout << t;
            return;
        }
        if (clip <= 1000) {
            q.push({ c,c,t + 1 });
        }
        if (c + clip <= 2000) {
            if (!visited[clip][c + clip]) {
                q.push({ c + clip,clip,t + 1 });
                visited[clip][c + clip] = 1;
            }
        }
        if (c - 1 >= 2) {
            q.push({ c - 1,clip,t + 1 });
            visited[clip][c - 1] = 1;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}