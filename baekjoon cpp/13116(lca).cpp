#include <bits/stdc++.h>
using namespace std;

int t, a, b;

int parent(int x)
{
    if (x == 1)
        return 1;
    else
        return (x - 2) / 2 + 1;
}

void solve()
{
    while (a != b)
    {
        if (a < b)
            swap(a, b);
        a = parent(a);
    }
    cout << a * 10 << '\n';
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> a >> b;
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}