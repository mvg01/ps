#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, s, e;
vector<pair<int, int>>v[100001];
int visited[100001];

bool bfs(int w) {
    queue<int>q;
    for (int i = 1; i <= n; i++)
        visited[i] = 0;
    for (int i = 0; i < v[s].size(); i++) {
        if (v[s][i].second >= w) {
            q.push(v[s][i].first);
            visited[v[s][i].first] = 1;
        }
    }
    while (!q.empty()) {
        int ver = q.front();
        q.pop();
        if (ver == e) 
            return 1;
        for (int i = 0; i < v[ver].size(); i++) {
            int next_ver = v[ver][i].first;
            int weight = v[ver][i].second;
            if (!visited[next_ver] && w <= weight) {
                q.push(next_ver);
                visited[next_ver] = 1;
            }
        }
    }
    return 0;
}

void solve() {
    int start = 0, end = 1000000, mid, res = 0;
    while (start <= end) {
        mid = (start + end) / 2;  // 들고갈 빼빼로 개수
        bool q = bfs(mid);
        if (!q)
            end = mid - 1;
        else {  // 들고 갈 수 있다면
            start = mid + 1;
            res = max(res, mid);
        }
    }
    cout << res;
}

void input() {
    cin >> n >> m >> s >> e;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
    solve();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}