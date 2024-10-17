#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int n, c;
int a[1000001];
void input() {
    cin >> n >> c;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void solve() {
    sort(a, a + n);
    ll s = 1, e = 1000000000, mid, res = 0, left = 0;
    while (s <= e) {
        mid = (s + e) / 2;
        ll cnt = 0;
        for (int i = 0; i < n; i++) 
            cnt += a[i] / mid;
        
        if (cnt >= c) {
            if (res < mid) {
                res = mid;
                ll x = 0;
                if (cnt > c) // 만들어야 하는 파닭의 수 보다 많이 만드는 mid 값
                    x += mid * (cnt - c);
                for (int i = 0; i < n; i++)
                    x += a[i] % mid;
                left = x;
            }
            s = mid + 1;
        }
        else
            e = mid - 1;
    }
    cout << left;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}