#include <bits/stdc++.h>
using namespace std;

int t, m;
vector<pair<int, double>>v[4];
double ans[4];

void bfs(int s) {
    double temp[4] = { 0, };
    queue<tuple<int, int, double>>q;
    q.push({ s,0,1.0 });
    while (q.size()) {
        auto f = q.front();
        q.pop();
        if (get<1>(f) == t) {
            temp[get<0>(f)] += get<2>(f);
            continue;
        }
        for (auto i : v[get<0>(f)]) 
            q.push({ i.first,get<1>(f) + 1,get<2>(f) * i.second });
    }
    for (int i = 0; i < 4; i++)
        ans[i] += temp[i] / 4.0;
}

void solve() {
    for (int i = 0; i < 4; i++)
        bfs(i);
    for (int i = 0; i < 4; i++)
        cout << ans[i] * 100.0 << '\n';
}

void input() {
    cin >> t >> m;
    for (int i = 0; i < m; i++) {
        char a, b; double c;
        cin >> a >> b >> c;
        v[a - 'A'].push_back({ b - 'A',c });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed << setprecision(2);
    input();
    solve();
}