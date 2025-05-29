#include <bits/stdc++.h>
using namespace std;

int x[3], y[3], q;

void solve()
{
    for (int i = 0; i < q; i++)
    {
        int cx, cy, t[3], dis[3];
        cin >> cx >> cy >> t[0] >> t[1] >> t[2];
        for (int j = 0; j < 3; j++)
            dis[j] = abs(x[j] - cx) + abs(y[j] - cy);
        int ans = 1e9;
        for (int j = 0; j < 3; j++)
        {
            int temp = (dis[j] + t[j] - 1) / t[j] * t[j];
            ans = min(ans, temp);
        }
        cout << ans << '\n';
    }
}

void input()
{
    for (int i = 0; i < 3; i++)
        cin >> x[i] >> y[i];
    cin >> q;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}