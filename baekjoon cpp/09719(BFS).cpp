#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int vis[31];
vector<int>v[31];

void solve() {
    int cnt = 0;
    queue<pair<int, int>>q;
    for (int i = 0; i < n; i++) {  // 0부터 모든 정점의 시작을 탐색하며 색칠하기 
        if (vis[i])
            continue;
        q.push({ i,1 });
        vis[i] = 1;
        cnt++;  // 색 경우의 수 
        while (q.size()) {
            int x = q.front().first;
            int c = q.front().second;
            q.pop();
            for (int i = 0; i < v[x].size(); i++) {
                int color, nxt = v[x][i];
                if (c == 1)
                    color = 2;
                else
                    color = 1;
                if (vis[nxt] == c) {  // 연결할 정점에 같은 색이 이미 있는 경우
                    cout << -1 << '\n';
                    return;
                }
                if (!vis[nxt]) {  
                    q.push({ nxt,color });
                    vis[nxt] = color;
                    continue;
                }
            }
        }
    }
    if (cnt == 0)
        cout << -1 << '\n';
    else
        cout << (int)pow(2, cnt) << '\n';
}

void input() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        getchar();  // 공백 한줄 입력받기
        solve();
        for (int i = 0; i < n; i++) {
            v[i].clear();
            vis[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}