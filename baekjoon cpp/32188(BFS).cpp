#include <bits/stdc++.h>
using namespace std;

int n, c, t, a, b;
int vis[100005][3], red[100001], blue[100001];

void solve() {
    deque<pair<int, int>>d;
    d.push_back({ 0,0 });
    vis[0][0] = 1;
    while (d.size()) {
        int ver = d.front().first;
        int tim = d.front().second;
        d.pop_front();
        if (ver == n - 1) {
            cout << tim;
            return;
        }
        if (red[ver] != -1) {  
            if (!vis[red[ver]][1]) {
                d.push_front({ red[ver], tim }); 
                vis[red[ver]][1] = 1;
            }
        }
        else if (blue[ver] != -1) {
            if (!vis[blue[ver]][2]) {
                d.push_front({ blue[ver], tim });
                vis[blue[ver]][2] = 1;
            }
            if (ver + 1 < n && !vis[ver + 1][0]) {
                d.push_back({ ver + 1, tim + 1 });
                vis[ver + 1][0] = 1;
            }
        }
        else {
            if (ver + 1 < n && !vis[ver + 1][0]) {
                d.push_back({ ver + 1, tim + 1 }); 
                vis[ver + 1][0] = 1;
            }
        }
    }
    cout << -1;
}

void input() {
    cin >> n >> c;
    memset(red, -1, sizeof(red));
    memset(blue, -1, sizeof(blue));
    for (int i = 0; i < c; i++) {
        cin >> t >> a >> b;
        if (t)
            blue[a] = b;
        else
            red[a] = b;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}