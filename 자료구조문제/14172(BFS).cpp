#include <bits/stdc++.h>
using namespace std;

int n, r = 0;
int visited[201];
vector<pair<pair<int, int>, int>>v;
void input() {
    cin >> n;
    int a, b, c;
    for (int i = 0; i < n; i++) {
        cin >> a >> b >> c;
        v.push_back({ {b,a},c });
    }
}

void init() {
    for (int i = 0; i < n; i++)
        visited[i] = 0;
}

int bfs(int idx, pair<int, int>z, int p) {
    int y = z.first;
    int x = z.second;
    int cnt = 1;
    queue<tuple<int, int, int>>q;
    q.push({ y,x,p });
    visited[idx] = 1;
    while (!q.empty()) {
        y = get<0>(q.front());
        x = get<1>(q.front());
        int d = get<2>(q.front());
        q.pop();
        for (int i = 0; i < n; i++) {
            if (visited[i])
                continue;
            int yy = v[i].first.first;
            int xx = v[i].first.second;
            double dis = sqrt(pow((yy - y), 2) + pow((xx - x), 2));
            if (dis <= d) {
                q.push({ yy,xx,v[i].second });
                visited[i] = 1;
                cnt++;
            }
        }
    }
    return cnt;
}

void solve() {
    for (int i = 0; i < n; i++) {
        init();
        int c = bfs(i, v[i].first, v[i].second);
        r = max(r, c);
    }
    cout << r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}