#include <bits/stdc++.h>
using namespace std;

int t, x, y, a[5];
bool chk;

void solve(int sum, int idx)
{
    if (idx == 5)
    {
        if (sum >= x && sum <= y)
            chk = 1;
        return;
    }
    solve(sum + a[idx], idx + 1);
    solve(sum, idx + 1);
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> x >> y;
        for (int i = 0; i < 5; i++)
            cin >> a[i];
        chk = 0;
        solve(0, 0);
        if (chk)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}