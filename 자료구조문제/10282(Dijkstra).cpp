#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#define INF 999999999

int t, n, d, c;
vector<pair<int, int>>v[100001];
int dis[100001];

void solve() {
    priority_queue<pair<int, int>>pq;
    for (int i = 0; i <= n; i++)
        dis[i] = INF;
    dis[c] = 0;
    for (int i = 0; i < v[c].size(); i++) {
        pq.push({ -v[c][i].second, v[c][i].first });
        dis[v[c][i].first] = v[c][i].second;
    }
    while (!pq.empty()) {
        int distance = -pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[ver].size(); i++) {
            int next_vertex = v[ver][i].first;
            int next_dis = v[ver][i].second;
            if (dis[next_vertex] > distance + next_dis) {
                dis[next_vertex] = distance + next_dis;
                pq.push({ -dis[next_vertex],next_vertex });
            }
        }
    }
}

void input() {
    cin >> t;
    while (t--) {
        int a, b, s;
        cin >> n >> d >> c;
        for (int i = 0; i < d; i++) {
            cin >> a >> b >> s;
            v[b].push_back({ a,s });
        }
        solve();
        int cnt = 0, ans = 0;
        for (int i = 1; i <= n; i++) {
            if (dis[i] != INF) {
                cnt++;
                ans = max(ans, dis[i]);
            }
        }
        cout << cnt << ' ' << ans << '\n';
        for (int i = 1; i <= n; i++) 
            v[i].clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}