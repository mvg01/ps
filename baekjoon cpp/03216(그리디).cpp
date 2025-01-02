#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>>v;

void solve() {
    int ans = v[0].second;
    int dif = v[0].first;
    for (int i = 1; i < n; i++) {
        if (dif - v[i].second >= 0) 
            dif -= v[i].second;
        else {
            ans += v[i].second - dif;
            dif = 0;
        }
        dif += v[i].first;
    }
    cout << ans;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        v.push_back({ a,b });
    }
}  

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}