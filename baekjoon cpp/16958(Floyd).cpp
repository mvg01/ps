#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, t;
int mat[1001][1001];
vector<tuple<int, int, int>>v;

void solve() {
    for (int i = 0; i < 1001; i++) {
        for (int j = 0; j < 1001; j++)
            mat[i][j] = INF;
    }
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            auto a = v[i], b = v[j];
            int d1 = abs(get<1>(a) - get<1>(b));
            int d2 = abs(get<2>(a) - get<2>(b));
            int dis = d1 + d2;
            mat[i][j] = dis;
            mat[j][i] = dis;
            if (get<0>(a) == 1 && get<0>(b) == 1) {
                mat[i][j] = min(dis, t);
                mat[j][i] = min(dis, t);
            }
        }
    }
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) 
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]);      
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        cout << mat[x - 1][y - 1] << '\n';
    }
}

void input() {
    cin >> n >> t;
    for (int i = 0; i < n; i++) {
        int s, x, y;
        cin >> s >> x >> y;
        v.push_back({ s,x,y });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}