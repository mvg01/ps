#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
vector<int> v[100001];
ll sum[100001];

void dfs(int start)
{
    for (int i = 0; i < v[start].size(); i++)
    {
        sum[v[start][i]] += sum[start];
        dfs(v[start][i]);
    }
}

void solve()
{
    dfs(1);
    for (int i = 1; i <= n; i++)
        cout << sum[i] << ' ';
}

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int x;
        cin >> x;
        if (x != -1)
            v[x].push_back(i);
    }
    for (int i = 0; i < m; i++)
    {
        int j, w;
        cin >> j >> w;
        sum[j] += w;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}