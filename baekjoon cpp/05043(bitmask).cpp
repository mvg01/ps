#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, b;

void solve()
{
    ll p = (1ll << b + 1) - 1;
    if (n <= p)
        cout << "yes";
    else
        cout << "no";
}

void input()
{
    cin >> n >> b;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}