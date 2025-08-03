#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, p[300001];
vector<ll>v[300001];
priority_queue<pair<ll, ll>>q;
ll res = 0;

void solve() {
    for (int i = 1; i <= n; i++) 
        cin >> p[i];
    q.push({ p[1],1 });
    while (!q.empty()) {
        ll w = q.top().first;
        ll ver = q.top().second;
        q.pop();
        res += w;
        cout << res << '\n';
        for (int i = 0; i < v[ver].size(); i++) 
            q.push({ p[v[ver][i]], v[ver][i] });
    }
}

void input() {
    cin >> n;
    p[1] = 0;
    for (int i = 2; i <= n; i++) {
        int x;
        cin >> x;
        v[x].push_back(i);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}