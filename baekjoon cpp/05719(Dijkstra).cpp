#include <bits/stdc++.h>
#define INF 999999999
using namespace std;

/*
 일단 최단 경로를 구한다. 
첫번째 dijkstra 함수 : 최단경로를 구하면서 temp에 정점 정보를 저장해둔다. 
최단경로가 여러 개인 경우 확인
bfs로 최단경로 (정점 to 정점) 을 visited로 방문처리 해준다.

 두번째 dijkstra 과정
방문처리된 간선이라면 최단경로에 포함된 간선이므로 거리 비교를 하지 않고 구해준다.
 */

int n, m, s, d;
int dis[501];
bool visited[501][501];  // 최단경로의 정보 저장
vector<pair<int, int>>v[501];
vector<int>temp[501];  // 최단경로의 정보 저장 

void dijkstra() {
    for (int i = 0; i <= n; i++) dis[i] = INF;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({ 0,s });
    dis[s] = 0;
    while (!pq.empty()) {
        int dist = pq.top().first;
        int ver = pq.top().second;
        pq.pop();
        for (int i = 0; i < v[ver].size(); i++) {
            int next_ver = v[ver][i].first;
            int w = v[ver][i].second;
            if (visited[next_ver][ver])
                continue;
            if (dis[next_ver] > dist + w) {
                dis[next_ver] = dist + w;
                temp[next_ver].clear();
                temp[next_ver].push_back(ver);
                pq.push({ dist + w,next_ver });
            }
            else if (dis[next_ver] == dist + w) {  // 최단경로가 여러개인 경우도 있다.
                temp[next_ver].push_back(ver);
            }
        }
    }
}


void remove_shortest_path() {
    queue<int>q;
    q.push(d);
    while (!q.empty()) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < temp[x].size(); i++) {
            if (!visited[x][temp[x][i]]) {
                visited[x][temp[x][i]] = 1;
                q.push(temp[x][i]);
            }
        }
    }
}

void solve() {
    dijkstra(); 
    remove_shortest_path();
    dijkstra();
    if (dis[d] != INF)
        cout << dis[d] << '\n';
    else
        cout << -1 << '\n';
}

void input() {
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) break;
        cin >> s >> d;
        for (int i = 0; i < m; i++) {
            int a, b, c;
            cin >> a >> b >> c;
            v[a].push_back({ b,c });
        }
        solve();
        for (int i = 0; i <= n; i++) {
            v[i].clear();
            temp[i].clear();
            for (int j = 0; j <= n; j++)
                visited[i][j] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}