#include <bits/stdc++.h>
using namespace std;

int n, m, r, y;
int a[100001];
int parent[100001];

int getParent(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = getParent(parent[x]);  // 효율적인 경로 압축
}

void set_union(int x, int y) {
    int r1 = getParent(x);
    int r2 = getParent(y);
    if (r1 < r2)
        parent[r2] = r1;
    else
        parent[r1] = r2;
}

void solve() {
    int ans = 0;
    for (int i = 0; i < n - 1; i++) {
        if (getParent(a[i]) != getParent(a[i + 1]))  // 최상위 부모 탐색
            ans++;
    }
    cout << ans;
}

void input() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> r >> y;
        set_union(r, y);
    }
    for (int i = 0; i < n; i++) 
        cin >> a[i];  
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}