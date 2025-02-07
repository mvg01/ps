#include <bits/stdc++.h>
#define INF 1e9;
using namespace std;

int n, w;
double m;
vector<pair<int, int>>v;
vector<pair<int, double>>mat[1001];
bool c[1001][1001];
double dis[1001];

void solve() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (c[i + 1][j + 1]) {
                mat[i + 1].push_back({ j + 1,0 });
                mat[j + 1].push_back({ i + 1,0 });
            }
            else {
                double d = sqrt(pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2));
                if (d < m) {
                    mat[i + 1].push_back({ j + 1,d });
                    mat[j + 1].push_back({ i + 1,d });
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
        dis[i] = (double)INF;
    priority_queue<pair<double, int>> pq; 
    dis[1] = 0; 
    pq.push({ 0,1 }); 
    while (!pq.empty()) {
        double distance = -pq.top().first;
        int cur = pq.top().second;
        pq.pop();
        for (auto i:mat[cur]) {
            int next = i.first;
            double cost = i.second;
            if (dis[next] > cost + distance) {
                dis[next] = cost + distance;
                pq.push({ -dis[next],next });
            }
        }
    }
    cout << (int)(dis[n] * 1000);
}

void input() {
    cin >> n >> w >> m;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({ a,b });
    }
    for (int i = 0; i < w; i++) {
        cin >> a >> b;
        c[a][b] = 1;
        c[b][a] = 1;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}s