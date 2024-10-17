#include <bits/stdc++.h>
using namespace std;

int n, m, x;
vector<int> v[200001];
vector<int> t;
int res[200001];
queue<pair<int, int> > q;

void bfs() {
    while (q.size()) {
        int p = q.front().first;
        int c = q.front().second;  // 루머를 믿게 된 시간
        q.pop();
        vector<int> b;
        for (int i = 0; i < v[p].size(); i++) {
            int y = v[p][i];
            if (res[y] != -1)
                continue;
            int cnt = 0;
            for (int j = 0; j < v[y].size(); j++)
                if (res[v[y][j]] <= c && res[v[y][j]] != -1) cnt++;
            if (v[y].size() % 2 && cnt >= v[y].size() / 2 + 1) {  // 루머를 믿게 된 시간도 체크해줘야 함, 혹은 큐를 2개 써서 관리
                q.push({y, c + 1});
                b.push_back(y);
            } else if (v[y].size() % 2 == 0 && cnt >= v[y].size() / 2) {
                q.push({y, c + 1});
                b.push_back(y);
            }
        }
        for (int i = 0; i < b.size(); i++) {
            res[b[i]] = c + 1;
        }
    }
}

void solve() {
    bfs();
    for (int i = 1; i <= n; i++) cout << res[i] << ' ';
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        res[i] = -1;
        while (1) {
            cin >> x;
            if (x == 0) break;
            v[i].push_back(x);
        }
    }
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        q.push({x, 0});
        res[x] = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}
