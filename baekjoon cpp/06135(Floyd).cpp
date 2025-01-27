// 1. Floyd-Warshall 풀이 O(N^3) ~= 27,000,000

#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, t, ans;
int dis[301][301];

void solve() {
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                dis[i][j] = min(dis[i][j], max(dis[i][k], dis[k][j]));
        }
    }
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        if (dis[a][b] == INF)
            cout << -1 << '\n';
        else
            cout << dis[a][b] << '\n';
    }
}

void input() {
    cin >> n >> m >> t;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (i != j)
                dis[i][j] = INF;
        }
    }
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        dis[a][b] = c;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}


// 2. Dijkstra 풀이  O(N*(N+M)*log(N)) ~= 68,310,000

#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, t, dis[301][301], ans;
vector<pair<int, int>>v[301];

void dijkstra(int s) {
    for (int i = 1; i <= n; i++) dis[s][i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
    pq.push({ 0,s });
    dis[s][s] = 0;
    while (pq.size()) {
        int d = pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[ver].size(); i++) {
            int nxt_ver = v[ver][i].first;
            int nxt_d = v[ver][i].second;
            if (dis[s][nxt_ver] > max(nxt_d, d)) {
                dis[s][nxt_ver] = max(nxt_d, d);
                pq.push({ max(nxt_d, d),nxt_ver });
            }
        }
    }
}
void solve() {
    for (int a = 1; a <= n; a++) 
        dijkstra(a);
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        ans = dis[a][b];
        if (ans == INF)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
}

void input() {
    cin >> n >> m >> t;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}

 
// 3. BFS 풀이  O(N*(N+M)) ~= 7,590,000
#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, t, dis[301][301], ans;
vector<pair<int, int>>v[301];

void bfs(int s) {
    for (int i = 1; i <= n; i++) dis[s][i] = INF;
    queue<pair<int, int>>q;
    q.push({ s,0 });
    dis[s][s] = 0;
    while (q.size()) {
        auto [ver, p] = q.front();
        q.pop();
        for (auto i : v[ver]) {
            if (dis[s][i.first] > max(p, i.second)) {
                dis[s][i.first] = max(p, i.second);
                q.push({ i.first, max(p,i.second) });
            }
        }
    }
}
void solve() {
    for (int a = 1; a <= n; a++)
        bfs(a);
    for (int i = 0; i < t; i++) {
        int a, b;
        cin >> a >> b;
        ans = dis[a][b];
        if (ans == INF)
            cout << -1 << '\n';
        else
            cout << ans << '\n';
    }
}

void input() {
    cin >> n >> m >> t;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        v[a].push_back({ b,c });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}