#include <bits/stdc++.h>
using namespace std;

int t, n;

void solve()
{
    if (n % 2 == 0)
        for (int i = 0; i < n; i++)
            cout << 1;
    else
    {
        if (n == 1)
            cout << 0;
        else
        {
            cout << 1;
            for (int i = 0; i < n - 2; i++)
                cout << 2;
            cout << 1;
        }
    }
    cout << '\n';
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}