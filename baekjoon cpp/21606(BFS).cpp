#include <bits/stdc++.h>
using namespace std;

long long ans = 0;
int n, cnt;
vector<int>v[200001];
bool vis[200001], chk[200001];
queue<int>q;

void bfs(int s) {
    queue<int>q;
    q.push(s);
    vis[s] = 1;
    cnt = 0;
    while (q.size()) {
        int s = q.front();
        q.pop();
        for (int i = 0; i < v[s].size(); i++) {
            int nxt = v[s][i];
            if (!vis[nxt]) {
                if (chk[nxt])
                    cnt++;
                else {
                    q.push(nxt);
                    vis[nxt] = 1;
                }
            }
        }
    }
    // cnt가 2 이상인 경우의 수만 체크
    ans += cnt * (cnt - 1);
}

void check(int s) {
    vis[s] = 1;
    for (int i = 0; i < v[s].size(); i++) {
        int nxt = v[s][i];
        if (!vis[nxt]) 
            ans += 2;
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        if (!vis[i] && !chk[i])  // 실외에서 탐색

            bfs(i);
    }
    for (int i = 1; i <= n; i++) {
        if (chk[i])  // 실내 to 실내
            check(i);
    }
    cout << ans;
}

void input() {
    string s;
    cin >> n >> s;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') chk[i + 1] = 1;
        else chk[i + 1] = 0;
    }
    for (int i = 0; i < n - 1; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}