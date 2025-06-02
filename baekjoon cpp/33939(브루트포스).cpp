#include <bits/stdc++.h>
using namespace std;

int n, m, ans = 0;
vector<int> v[2001];
bool c[2001][2001];
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() > 1)
        {
            for (int j = 0; j < v[i].size() - 1; j++)
            {
                for (int k = j + 1; k < v[i].size(); k++)
                {
                    if (!c[v[i][j]][v[i][k]])
                        ans++;
                }
            }
        }
    }
    cout << ans;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[b].push_back(a);
        c[a][b] = 1;
        c[b][a] = 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}