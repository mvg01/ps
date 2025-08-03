#include <bits/stdc++.h>
using namespace std;

int n, a[1000001], res[1000001];
stack<int>s;
void solve() {
    if (a[0] != 1) { 
        cout << -1;
        return;
    }
    s.push(a[n - 1]);
    for (int i = n - 2; i >= 0; i--) {
        int t = s.top();
        if (t <= a[i])
            s.push(a[i]);
        else {
            while (s.size()) {
                if (s.top() - 1 == a[i]) {
                    s.pop();
                    res[i]++;
                }
                else if (s.top() > a[i]) {
                    cout << -1;
                    return;
                }
                else 
                    break; 
            }
            s.push(a[i]);
        }
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << '\n';
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}