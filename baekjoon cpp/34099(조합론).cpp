#include <bits/stdc++.h>
using namespace std;

int t, n, k;

void solve()
{
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        if (k == 1)
        {
            if (n < 4)
                cout << -1 << '\n';
            else
            {
                for (int i = 2; i <= n; i += 2)
                    cout << i << " ";
                for (int i = 1; i <= n; i += 2)
                    cout << i << " ";
                cout << '\n';
            }
        }
        else
        {
            for (int i = 1; i <= n; i++)
                cout << i << " ";
            cout << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}