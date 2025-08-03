#include <iostream>
using namespace std;
using ll = long long;

ll solve(ll a, ll b, ll c) {
    if (b == 1)
        return a % c;
    ll temp = solve(a, b / 2, c);
    if (b % 2 == 0)
        return temp * temp % c;
    else
        return temp * temp % c * a % c;
}

void input() {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << solve(a % c, b, c); // long long overflow 방지
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}