#include <bits/stdc++.h>
using namespace std;

int n, l, b[11], ans;
bool vis[2301];
void solve()
{
    int idx = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        q.push(i);
    while (q.size())
    {
        for (int i = 0; i < b[idx] - 1; i++)
        {
            int x = q.front();
            q.pop();
            q.push(x);
        }
        if (q.size() == 1)
            ans = q.front();
        q.pop();
        idx++;
        if (idx == l)
            idx = 0;
    }
    cout << ans;
}

void input()
{
    cin >> n >> l;
    for (int i = 0; i < l; i++)
        cin >> b[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}