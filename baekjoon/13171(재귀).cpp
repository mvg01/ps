#include <iostream>
using namespace std;
using ll = long long;
#define MOD 1000000007

ll solve(ll a, ll x) {
    if (x == 1)
        return a % MOD;
    ll temp = solve(a, x / 2);
    if (x % 2 == 0)
        return temp * temp % MOD;
    else
        return temp * temp % MOD * a % MOD;
}

void input() {
    ll a, x;
    cin >> a >> x;
    cout << solve(a % MOD, x); // long long overflow 방지
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}