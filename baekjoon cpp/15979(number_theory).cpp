#include <bits/stdc++.h>
using namespace std;

int n, m;
void solve()
{
    if (n == 0 && m == 0)
    {
        cout << 0;
        return;
    }
    n = abs(n);
    m = abs(m);
    if (gcd(n, m) == 1)
        cout << 1;
    else
        cout << 2;
}

void input()
{
    cin >> n >> m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}