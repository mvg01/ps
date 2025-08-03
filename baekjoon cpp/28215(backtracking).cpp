#include <bits/stdc++.h>
#define INF 999999999
using namespace std;

int n, k, res = INF;
pair<int, int>a[51];
int visited[51];

void input() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
}

void bt(int cnt, vector<pair<int, int>> v) {
    if (cnt == k) {
        int temp = 0;
        for (int i = 0; i < n; i++) {
            int mn = INF;
            for (int j = 0; j < k; j++) {
                int m = abs(v[j].first - a[i].first) + abs(v[j].second - a[i].second);
                mn = min(mn, m);
            }
            temp = max(temp, mn);
        }
        res = min(res, temp);
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            visited[i] = 1;
            v.push_back(a[i]);
            bt(cnt + 1, v);
            visited[i] = 0;
            v.erase(v.begin() + (v.size() - 1));
        }
    }
}

void solve() {
    vector<pair<int, int>>v;
    bt(0, v);
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}