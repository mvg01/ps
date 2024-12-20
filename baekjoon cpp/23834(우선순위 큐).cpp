#include <bits/stdc++.h>
using namespace std;

int n, m, a[10001];
priority_queue<int, vector<int>, greater<int>>q;  // min heap

void solve() {
    sort(a, a + n, greater<int>());  // 내림차순 정렬 (시간이 오래걸리는 것 부터 충전이 유리함)
    int idx = m, ans = a[0];
    for (int i = 0; i < m; i++) 
        q.push(a[i]);
    while (idx < n) {
        int x = q.top();
        q.pop();
        q.push(a[idx] + x);
        ans = max(ans, a[idx++] + x);
    }
    while (q.size()) {
        int x = q.top();
        q.pop();
        ans = max(ans, x);
    }
    cout << ans;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}