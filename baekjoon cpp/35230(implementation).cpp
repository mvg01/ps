#include <bits/stdc++.h>
using namespace std;

int n, a[1001], ans;
void solve()
{
    for (int i = 0; i <= n; i++)
    {
        if (a[i] == 0)
            continue;
        if (a[i] >= i)
            ans += a[i] - i;
        else
            ans += a[i];
    }
    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        a[x]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}