#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, a, b, c;
int dis[4001][3];
bool vis[4001][2];
vector<pair<int, int>>v[4001];

void dijkstra() {
    for (int i = 1; i <= n; i++)
        dis[i][0] = INF;
    priority_queue<pair<int, int>>pq;
    dis[1][0] = 0;
    pq.push({ 0,1 });
    while (!pq.empty()) {
        int dist = -pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        for (auto i : v[ver]) {
            int next_ver = i.first;
            int next_dis = i.second;
            if (dis[next_ver][0] > dist + next_dis) {
                dis[next_ver][0] = dist + next_dis;
                pq.push({ -dis[next_ver][0],next_ver });
            }
        }
    }
}

void dijkstra2() {
    for (int i = 1; i <= n; i++) {
        dis[i][1] = INF;
        dis[i][2] = INF;
    }
    dis[0][2] = 0;
    priority_queue<tuple<int, int, bool>>pq;
    pq.push({ 0,1,0 });
    while (!pq.empty()) {
        int dist = -get<0>(pq.top());
        int ver = get<1>(pq.top());
        bool skill = get<2>(pq.top());  // skill이 0일때 2배 짧게 이동
        pq.pop();

        if (vis[ver][skill]) 
            continue;
        vis[ver][skill] = 1;

        for (auto i : v[ver]) {
            int next_ver = i.first;
            int next_dis = i.second;
            if (!skill) {  
                next_dis /= 2;
                if (dis[next_ver][1] > dist + next_dis) {
                    dis[next_ver][1] = dist + next_dis;
                    pq.push({ -dis[next_ver][1],next_ver,!skill });
                }
            }
            else {
                next_dis *= 2;
                if (dis[next_ver][2] > dist + next_dis) {
                    dis[next_ver][2] = dist + next_dis;
                    pq.push({ -dis[next_ver][2],next_ver,!skill });
                }
            }
        }
    }
}

void solve() {
    dijkstra();
    dijkstra2();
    int ans = 0;
    for (int i = 2; i <= n; i++) {
        if (dis[i][0] < min(dis[i][1], dis[i][2]))
            ans++;
         // cout << dis[i][0] << ' ' << min(dis[i][1], dis[i][2]) << '\n';
    }
    cout << ans;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        c *= 2;
        v[a].push_back({ b,c });
        v[b].push_back({ a,c });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}