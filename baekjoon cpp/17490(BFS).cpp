#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
ll k;
bool vis[1000001];
vector<pair<int, int>>v;
map<pair<int, int>, bool>ma;

void bfs(int s) {
    queue<int>q;
    q.push(s);
    vis[s] = 1;
    while (q.size()) {    // 양 옆의 강의동으로 이동 가능하다면 큐에 넣고 방문체크
        int x = q.front();
        q.pop();
        int temp = x;
        if (!vis[(x % n) + 1] && !ma[{temp, (x % n) + 1}]) {
            vis[(x % n) + 1] = 1;
            q.push((x % n) + 1);
        }
        if (!vis[(x - 2 + n) % n + 1] && !ma[{(x - 2 + n) % n + 1, temp}]) {
            vis[(x - 2 + n) % n + 1] = 1;
            q.push((x - 2 + n) % n + 1);
        }
    }
}

void solve() {
    if (m < 2) {    // 중앙 섬을 이용하지 않고 가능
        cout << "YES";
        return;
    }
    sort(v.begin(), v.end());  // 적은 돌로 이동 가능한 강의실부터 (그리디)
    for (auto i : v) {
        if (!vis[i.second]) {   
            k -= i.first;
            if (k < 0) {
                cout << "NO";
                return;
            }
            bfs(i.second);
        }
    }
    cout << "YES";
}

void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        v.push_back({ s,i + 1 });
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        ma[{a, b}] = 1;  // 공사중인 곳 저장
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}