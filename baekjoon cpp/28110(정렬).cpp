#include <bits/stdc++.h>
using namespace std;

int n, a[3001];
vector<pair<int, int>>v;

bool com(pair<int, int>x, pair<int, int>y) {
    if (x.first > y.first)
        return 1;
    else if (x.first < y.first)
        return 0;
    else {
        if (x.second < y.second)
            return 1;
        else
            return 0;
    }
}

void solve() {
    sort(a, a + n);
    for (int i = 1; i < n; i++) {
        int b = a[i] - a[i - 1];
        if (b == 1)
            continue;
        v.push_back({ b / 2,a[i - 1] + b / 2 });
    }
    if (v.empty()) {
        cout << -1;
        return;
    }
    sort(v.begin(), v.end(), com);
    cout << v[0].second;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}