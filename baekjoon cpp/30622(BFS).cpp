#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n;
ll ans = 0;
int di[8][2] = { {-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1} };
vector<tuple<int, int, int>>v;
map<pair<int, int>, int>m;
map<pair<int, int>, bool>vis;  // 방문처리를 map으로

bool c(tuple<int, int, int>a, tuple<int, int, int>b) {
    return get<2>(a) < get<2>(b);
}

void solve() {
    sort(v.begin(), v.end(), c);  // (0,0) 에서 가까운 순으로 정렬
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        auto [y, x, d] = v[i];
        if (vis.find({ y,x }) != vis.end())
            continue;
        queue<pair<int, int>>q;
        q.push({ y,x });
        vis.insert({ {y,x},1 });
        cnt++;
        while (q.size()) {
            auto [yy, xx] = q.front();
            q.pop();
            if (cnt == n) {
                cout << ans * 2 + d;
                return;
            }
            for (int j = 0; j < 8; j++) {
                int dy = yy + di[j][0];
                int dx = xx + di[j][1];
                if (vis.find({ dy,dx }) != vis.end())
                    continue;
                if (m.find({ dy,dx }) != m.end()) {
                    q.push({ dy,dx });
                    vis.insert({ { dy,dx }, 1 });
                    cnt++;
                }
            }
        }
        ans += d;
    }
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y;
        cin >> x >> y;
        int dis = abs(x) + abs(y);
        m.insert({ {y,x},1 });
        v.push_back({ y,x,dis });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}