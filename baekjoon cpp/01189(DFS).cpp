#include <bits/stdc++.h>
using namespace std;

char mat[6][6];
int d[4][2] = { {0,1},{-1,0},{0,-1}, {1,0} };
int v[26];
int r, c, k, res = 0;
void input() {
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++)
        cin >> mat[i];
}

void bt(int y, int x, int dis) {
    if (dis==k) {
        if (y == 0 && x == c - 1)
            res++;
        return;
    }
    for (int i = 0; i < 4; i++) {
        int yy = y + d[i][0];
        int xx = x + d[i][1];
        if (yy >= r || yy < 0 || xx >= c || xx < 0)
            continue;
        if (mat[yy][xx] != 'T' && !v[yy * c + xx]) {
            v[yy * c + xx] = 1;
            bt(yy, xx, dis + 1);
            v[yy * c + xx] = 0;
        }
    }
}

void solve() {
    v[(r - 1) * c] = 1;
    bt(r - 1, 0, 1);
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}