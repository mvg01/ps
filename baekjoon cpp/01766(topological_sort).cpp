#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> v[32001];
int d[32001], ans[32001];

void solve()
{
    priority_queue<int, vector<int>, greater<int>> q;
    for (int i = 1; i <= n; i++)
    {
        if (d[i] == 0)
            q.push(i);
    }
    for (int i = 0; i < n; i++) // 사이클 없음
    {
        int x = q.top();
        q.pop();
        ans[i] = x;
        for (auto i : v[x])
        {
            int nxt = i;
            d[nxt]--;
            if (d[nxt] == 0)
                q.push(nxt);
        }
    }
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        d[b]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}