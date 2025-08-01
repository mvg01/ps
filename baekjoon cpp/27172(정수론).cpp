#include <bits/stdc++.h>
using namespace std;

int n, a[100001], ans[100001], lose[1000001];
bool m[1000001];

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = a[i] * 2; j <= 1000000; j += a[i])
        {
            if (m[j])
            {
                ans[i]++;
                lose[j]++;
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] - lose[a[i]] << ' ';
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m[a[i]] = 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}