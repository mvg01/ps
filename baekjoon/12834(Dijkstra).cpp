#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;

int n, v, e, a, b, ans = 0;
int dis[1001];
vector<pair<int, int>>mat[1001];
vector<int>kist;

int solve(int start) {
    for (int i = 1; i <= v; i++) 
        dis[i] = INF;
    priority_queue <pair<int,int>>pq;
    dis[start] = 0;
    pq.push({ 0,start });
    while (!pq.empty()) {
        int distance = -pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        for (int i = 0; i < mat[ver].size(); i++) {
            int next_vertex = mat[ver][i].first;
            int next_dis = mat[ver][i].second;
            if (dis[next_vertex] > distance + next_dis) {
                dis[next_vertex] = distance + next_dis;
                pq.push({ -dis[next_vertex],next_vertex });
            }
        }
    }
    if (dis[a] == INF)
        dis[a] = -1;
    if (dis[b] == INF)
        dis[b] = -1;
    return dis[a] + dis[b];
}

void input() {
    int x, y, z;
    cin >> n >> v >> e >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> x;
        kist.push_back(x);
    }
    for (int i = 0; i < e; i++) {
        cin >> x >> y >> z;
        mat[x].push_back({ y,z });
        mat[y].push_back({ x,z });
    }
    for (int i = 0; i < n; i++)
        ans += solve(kist[i]);
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}