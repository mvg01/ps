#include <bits/stdc++.h>
using namespace std;

int n, m, t, a, b, e;
bool visited[100001];
int res[100001];
vector<int>mat[100001];
vector<int>mat2[100001];

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        mat[a].push_back(b);
        mat2[b].push_back(a);
    }
}

void bfs1(int s) {
    queue<int>q;
    for (int i = 0; i < mat[s].size(); i++) {
        q.push(mat[s][i]);
        visited[mat[s][i]] = 1;
        res[mat[s][i]]++;
    }
    while (!q.empty()) {
        int y = q.front();
        q.pop();
        for (int i = 0; i < mat[y].size(); i++) {
            if (visited[mat[y][i]])
                continue;
            q.push(mat[y][i]);
            visited[mat[y][i]] = 1;
            res[mat[y][i]]++;
        }
    }
}

void bfs2(int s) {
    queue<int>q;
    for (int i = 0; i < mat2[s].size(); i++) {
        q.push(mat2[s][i]);
        visited[mat2[s][i]] = 1;
        res[mat2[s][i]]++;
    }
    while (!q.empty()) {
        int y = q.front();
        q.pop();
        for (int i = 0; i < mat2[y].size(); i++) {
            if (visited[mat2[y][i]])
                continue;
            q.push(mat2[y][i]);
            visited[mat2[y][i]] = 1;
            res[mat2[y][i]]++;
        }
    }
}

void solve() {
    bfs1(1);  // 1 에서 2~n-1 도달 가능한지
    for (int i = 1; i <= n; i++) visited[i] = 0; 
    bfs2(n);  // n 에서 2~n-1 도달 가능한지
    cin >> t; 
    while (t--) {
        cin >> e;
        if (res[e] == 2)
            cout << "Defend the CTP\n";
        else
            cout << "Destroyed the CTP\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}