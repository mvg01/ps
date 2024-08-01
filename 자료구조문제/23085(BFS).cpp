#include <bits/stdc++.h>
using namespace std;

int n, k;
string s;
bool vis[3001];

void solve() {
    int h = 0, t = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'H') h++;
        else t++;
    }
    queue<pair<int, int> > q;
    q.push({t, 0}); // 뒷면의 개수 저장
    vis[t] = 1;
    while (q.size()) {
        int tt = q.front().first;
        int r = q.front().second;
        q.pop();
        if (tt == n) {
            cout << r;
            return;
        }
        int hh = n - tt;
        for (int i = 0; i <= k; i++) {
            int ttt = tt - i + (k - i);
            if (tt >= i && hh >= k - i && !vis[ttt]) {
                vis[ttt] = 1;
                q.push({ttt, r + 1});
            }
        }
    }
    cout << -1;
}

void input() {
    cin >> n >> k >> s;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}