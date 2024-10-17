#include <bits/stdc++.h>
using namespace std;

int n, m, s;
vector<int>mat[100001];
int visited[100001];
bool gom[100001];  // 팬클럽 곰곰이 정점

void input() {
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        mat[a].push_back(b);
    }
    cin >> s;
    for (int i = 0; i < s; i++) {
        cin >> a;
        gom[a] = 1;
    }
}

void solve() {
    if (gom[1]) {  // 시작 지점에 팬클럽
        cout << "Yes";
        return;
    }
    if (mat[1].empty()) { // 시작지점 간선 없음
        cout << "yes";
        return;
    }
    queue<int>q;
    for (auto i : mat[1]) {
        if (gom[i])
            continue;
        q.push(i);
        visited[i] = 1;
    }
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (gom[v])
            continue;
        if (mat[v].size() == 0) {
            cout << "yes";
            return;
        }
        for (auto i : mat[v]) {
            if (!visited[i]) {
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    cout << "Yes";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}