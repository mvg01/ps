#include <bits/stdc++.h>
using namespace std;

int n, k, a[100001], ans;
vector<int> v[100001];

void dfs(int node, int d)
{
    if (d > k)
        return;
    if (d <= k && a[node])
        ans++;
    for (auto i : v[node])
    {
        dfs(i, d + 1);
    }
}

void solve()
{
    dfs(0, 0);
    cout << ans;
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n - 1; i++)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
    }
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