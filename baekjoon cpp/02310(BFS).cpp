#include <bits/stdc++.h>
using namespace std;

int n, p[1001], vis[1001];
vector<pair<char, int>>t;  // 방의 정보 (문과 금액)
vector<int>v[1001];  // 연결된 방 리스트

void solve() {
    queue<pair<int, int>>q;
    q.push({ 0,0 });
    vis[0] = 0;
    v[0].push_back(1);
    while (q.size()) {
        int r = q.front().first;  // 연결된 방의 번호
        int m = q.front().second;  // 연결된 방의 금액 
        q.pop();
        if (r == n) {
            cout << "Yes\n";
            return;
        }
        for (int i = 0; i < v[r].size(); i++) {
            int next = v[r][i];
            char room_type = t[next - 1].first;
            int w = t[next - 1].second;
            if (room_type == 'E') {
                if (vis[next] < m) {
                    vis[next] = m;
                    q.push({ next,m });
                }
            }
            else if (room_type == 'L') {
                if (vis[next] < max(m, w)) {
                    vis[next] = max(m, w);
                    q.push({ next,vis[next] });
                }
            }
            else if (room_type == 'T') {
                if (m >= w && vis[next] <= m - w) {
                    vis[next] = m - w;
                    q.push({ next,vis[next] });
                }
            }
        }
    }
    cout << "No\n";
}

void input() {
    while (1) {
        cin >> n;
        if (n == 0) break;
        for (int i = 0; i < 1001; i++) {
            vis[i] = -1;
            v[i].clear();
        }
        t.clear();
        for (int i = 1; i <= n; i++) {
            char y;
            int x;
            cin >> y >> x;
            t.push_back({ y,x });
            while (1) {
                cin >> x;
                if (x == 0)
                    break;
                v[i].push_back(x);
            }
        }
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}