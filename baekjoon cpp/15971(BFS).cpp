#include <bits/stdc++.h>
using namespace std;

int n, a, b;
vector<pair<int, int>>mat[100001];
int visited[100001];
queue<pair<int, int>>q;

void input() {
    int q, w, e;
    cin >> n >> a >> b;
    for (int i = 0; i < n - 1; i++) {
        cin >> q >> w >> e;
        mat[q].push_back({ w,e });
        mat[w].push_back({ q,e });
    }
}

void solve(int s) {
    visited[s] = 1;
    q.push({ s,0 });
    while (!q.empty()) {
        int v = q.front().first;
        int dis = visited[v];
        int max_dis = q.front().second;
        q.pop();
        if (v == b) {
            cout << dis - 1 - max_dis;
            break;
        }
        for (int i = 0; i < mat[v].size(); i++) {
            int x = mat[v][i].first;
            int y = mat[v][i].second;
            if (visited[x])
                continue;
            q.push({ x,max(max_dis,y) });
            visited[x] = dis + y;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve(a);
}