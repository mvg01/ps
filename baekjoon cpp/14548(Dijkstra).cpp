#include <bits/stdc++.h>
#define INF 999999999
using namespace std;

int p, n, c;
string s, e, a, b;
vector<pair<int, int>>mat[501];
unordered_map<string, int>m;
int dis[501];
void solve() {
    for (int i = 0; i < 501; i++) dis[i] = INF;
    int start = m[s];
    int end = m[e];
    priority_queue<pair<int, int>> pq;
    pq.push({ 0,start });
    dis[start] = 0;
    while (!pq.empty()) {
        int distance = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (int i = 0; i < mat[cur].size(); i++) {
            int next = mat[cur][i].first;
            int cost = mat[cur][i].second;
            if (dis[next] > cost + distance) {
                dis[next] = cost + distance;
                pq.push({ -dis[next],next });
            }
        }
    }
    cout << s << ' ' << e << ' ' << dis[m[e]] << '\n';
    m.clear();
    for (int i = 0; i < 501; i++) mat[i].clear();
}

void input() {
    cin >> p;
    while (p--) {
        cin >> n >> s >> e;
        int idx = 0;
        for (int i = 0; i < n; i++) {
            cin >> a >> b >> c; 
            if (m.find(a) == m.end())
                m[a] = idx++;
            if (m.find(b) == m.end()) 
                m[b] = idx++;
            int ai = m[a];
            int bi = m[b];
            mat[ai].push_back({ bi,c });
            mat[bi].push_back({ ai,c });
        }
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}