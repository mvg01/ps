#include <bits/stdc++.h>
using namespace std;

int n, t, x, idx = 1;
deque<int>d;
void solve() {
    int cnt = 0, pre = -1;
    for (int i = 0; i < n; i++) {
        if (d.size() == 1) {
            x = d.front();
            if (pre <= x) 
                cnt++;
            break;
        }
        int ft = d.front();
        int bk = d.back();
        if (ft > bk) {
            d.pop_back();  
            if (pre <= bk) {
                cnt++;
                pre = bk;
            }
        }
        else {
            d.pop_front();
            if (pre <= ft) {
                cnt++;
                pre = ft;
            }
        }
    }
    cout << "Case #" << idx++ << ": " << cnt << '\n';
}

void input() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x;
            d.push_back(x);
        }
        solve();
        d.clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}
