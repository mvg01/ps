#include <bits/stdc++.h>
using namespace std;

int n;
bool vis[501][501];
vector<int> ans;

void dfs(int c)
{
    for (int i = 1; i <= n; i++)
    {
        if (i == c)
            continue;
        if (!vis[i][c])
        {
            vis[i][c] = 1;
            vis[c][i] = 1;
            dfs(i);
        }
    }
    ans.push_back(c);
}

void solve()
{
    dfs(1);
    reverse(ans.begin(), ans.end());
    for (int i : ans)
        cout << 'a' << i << ' ';
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