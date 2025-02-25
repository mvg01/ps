#include <bits/stdc++.h>
using namespace std;

// 분리집합: 하나의 부모에서 연결이 가능한지 체크위함
// 탐색: 가장 간선이 많은 정점에서 시작하여 간선을 방문처리

int v, e;
int p[3001];
vector<pair<int, int>>mat[3001];
bool vis[3001];

int get_parent(int x) {
    if (x == p[x])
        return x;
    else
        return p[x] = get_parent(p[x]);
}

void set_union(int a, int b) {
    int a1 = get_parent(a);
    int b1 = get_parent(b);
    if (a1 > b1)
        p[a1] = b1;
    else
        p[b1] = a1;
}

void solve() {
    int s = 0, mx = 0;   // 간선이 가장 많은 정점에서부터 묶기 시작
    for (int i = 1; i <= 3000; i++) {
        p[i] = i;
        if (mat[i].size() > mx) {
            s = i;
            mx = mat[i].size();
        }
    }
    for (int i = 0; i < e; i++) {
        int nxt = -1;
        for (auto j : mat[s]) {
            if (!vis[j.second]) {
                vis[j.second] = 1;
                nxt = j.first;
                break;
            }
        }
        if (nxt == -1) {  // 연결 가능한 간선이 없음
            cout << "NO";
            return;
        }
        set_union(get_parent(nxt), get_parent(s));  
        s = nxt;
    }
    for (int i = 1; i < v; i++) {
        if (get_parent(i) != get_parent(i + 1)) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

void input() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        mat[a].push_back({ b,i });
        mat[b].push_back({ a,i });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}