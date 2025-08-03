#include <bits/stdc++.h>
using namespace std;

int n, a[51], ans = 0;

void solve() {
    stack<int>c;  // 양수 스택
    queue<int>b;  // 음수 큐
    bool zero = 0;
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (a[i] < 0)
            b.push(a[i]);
        else if (a[i] > 0)
            c.push(a[i]);
        else zero = 1;
    }
    while (c.size() >= 2) {
        int t1 = c.top(); c.pop();
        int t2 = c.top(); c.pop();
        ans += (t1 * t2 > t1 + t2) ? t1 * t2 : t1 + t2;
    }
    if (c.size()) ans += c.top();
    while (b.size() >= 2) {
        int t1 = b.front(); b.pop();
        int t2 = b.front(); b.pop();
        ans += t1 * t2;
    }
    if (b.size()) {
        if (!zero)  // 0이 있으면 남은 음수랑 묶어줌
            ans += b.front();
    }
    cout << ans;
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