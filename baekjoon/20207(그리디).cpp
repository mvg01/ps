#include <iostream>
using namespace std;

int n;
int d[366] = { 0 };
void input() {
    cin >> n;
    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        for (int j = a; j <= b; j++)
            d[j]++;
    }
}

void solve() {
    int ans = 0, h = 0, cnt = 0;
    for (int i = 1; i <= 365; i++) {
        if (d[i] > 0) {
            h = max(h, d[i]);  // 겹치는 날의 개수 (높이)
            cnt++;  // 겹치는 날의 개수 (너비)
        }
        else {
            ans += h * cnt;
            cnt = 0; 
            h = 0;
        }
    }
    ans += h * cnt;
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}