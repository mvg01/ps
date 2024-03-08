#include <iostream>
using namespace std;

int n;
long long pre, cnt = 1, x, ans = 0;
void input() {
    cin >> n >> pre;
    for (int i = 1; i < n; i++) {
        cin >> x;
        if (pre < x)
            cnt++;
        else {
            ans += cnt * (cnt + 1) / 2;
            cnt = 1;
        }
        pre = x;
    }
    ans += cnt * (cnt + 1) / 2;
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}