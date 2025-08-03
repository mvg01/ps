#include <bits/stdc++.h>
using namespace std;
int n, a, b;
vector<int>yy[10001];
vector<int>xx[10001];

// 두 점 사이의 거리를 모두 찾는 풀이

void solve() {
    int ans = 0;
    for (int i = 0; i <= 10000; i++) {
        sort(yy[i].begin(), yy[i].end());
        sort(xx[i].begin(), xx[i].end());
        for (int j = 0; j < yy[i].size(); j+=2) 
            ans += yy[i][j + 1] - yy[i][j];
        for (int j = 0; j < xx[i].size(); j+=2) 
            ans += xx[i][j + 1] - xx[i][j];  
    }
    cout << ans;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        yy[b].push_back(a);
        xx[a].push_back(b);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}