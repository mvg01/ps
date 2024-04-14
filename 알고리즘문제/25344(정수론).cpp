#include <iostream>
#define ll long long
using namespace std;

ll gcd(ll x, ll y) {  // 최대공약수
    if (y == 0)
        return x;
    else
        return gcd(y, x % y);
}

ll lcm(ll a,ll b) { // 최소공배수
    return a * b / gcd(a, b);
}

void input() {
    ll n, x, res = 1;
    cin >> n;
    for (int i = 0; i < n - 2; i++) {
        cin >> x;
        res = lcm(x, res);
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}