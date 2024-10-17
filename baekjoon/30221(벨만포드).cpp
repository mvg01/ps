#include <bits/stdc++.h>
#define INF 999999999
using namespace std;

int n, m;
long long dis[5001];
vector<pair<pair<int, int>, int>>v;

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, d;
        char c;
        cin >> a >> b >> c >> d;
        if (c == 'b')
            v.push_back({ { a,b }, d });
        else
            v.push_back({ { a,b }, -d });
    }
}

void solve() {
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int s = v[j].first.first;
            int e = v[j].first.second;
            int w = v[j].second;
            if (dis[s] != INF) {
                if (dis[e] > dis[s] + w) {
                    dis[e] = dis[s] + w;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dis[i] < 0)
            cout << i << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}