#include <bits/stdc++.h>
using namespace std;

int n, mat[11][11], ans;
bool vis[21];
vector<pair<int, int>> v[21];

void bt(int idx, int cnt)
{
    if (idx >= n * 2 - 1)
    {
        ans = max(ans, cnt);
        return;
    }
    if (ans >= (n * 2 - 1) - idx + cnt)
        return;
    for (auto i : v[idx])
    {
        if (!vis[i.first - i.second + n - 1])
        {
            vis[i.first - i.second + n - 1] = 1;
            bt(idx + 1, cnt + 1);
            vis[i.first - i.second + n - 1] = 0;
        }
    }
    bt(idx + 1, cnt);
}

void solve()
{
    bt(0, 0);
    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] == 1)
            {
                v[i + j].push_back({i, j});
            }
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