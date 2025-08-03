#include <bits/stdc++.h>
using namespace std;

int n, k, a[51];

void solve()
{
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == i + 1)
            continue;
        else
        {
            if (a[i] > i + 1)
            {
                cout << 0;
                return;
            }
            bool go = 0;
            int idx = 0;
            for (int u = i; u < n; u++)
            {
                int t = a[u];
                for (int j = 0; j < 51; j += k)
                {
                    if (t + j == i + 1)
                    {
                        go = 1;
                        idx = u;
                        break;
                    }
                    else if (t + j > i + 1)
                        break;
                }
                if (go)
                {
                    a[idx] = a[i];
                    break;
                }
            }
            if (!go)
            {
                cout << 0;
                return;
            }
        }
    }
    cout << 1;
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}