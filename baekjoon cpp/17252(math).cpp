#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n;
bool vis[1001];

void solve()
{
    if (n == 0)
    {
        cout << "NO";
        return;
    }
    while (1)
    {
        for (int i = 0;; i++)
        {
            if (pow(3, i) > n)
            {
                if (vis[i - 1])
                {
                    cout << "NO";
                    return;
                }
                n -= pow(3, i - 1);
                vis[i - 1] = 1;
                break;
            }
        }
        if (n == 0)
            break;
    }
    cout << "YES";
}

void input()
{
    cin >> n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}