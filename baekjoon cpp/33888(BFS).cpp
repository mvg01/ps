#include <bits/stdc++.h>
using namespace std;

int n, ans[6];
vector<int> mat[51];
bool vis[51];
void solve()
{
    queue<int> q;
    // F 상어 찾기
    for (int i = 1; i <= n; i++)
    {
        if (mat[i].size() == 1)
        {
            ans[5] = i;
            vis[i] = 1;
            q.push(i);
            break;
        }
    }
    // E 상어 찾기
    while (q.size())
    {
        int x = q.front();
        q.pop();
        if (mat[x].size() == 4)
        {
            ans[4] = x;
            q.push(x);
            break;
        }
        for (auto i : mat[x])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    // B,C,D 상어 찾기
    int start_node = q.front();
    q.pop();
    for (int i = 0; i < 3; i++)
    {
        q.push(start_node);
        while (q.size())
        {
            int x = q.front();
            q.pop();
            if (mat[x].size() == 4 && x != start_node)
            {
                ans[2] = x;
                break;
            }
            else if (mat[x].size() == 3)
            {
                if (ans[1] == 0)
                    ans[1] = x;
                else
                    ans[3] = x;
                break;
            }
            for (auto i : mat[x])
            {
                if (!vis[i])
                {
                    vis[i] = 1;
                    q.push(i);
                    break;
                }
            }
        }
    }
    // A 상어 찾기
    q.push(ans[2]);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        if (mat[x].size() == 3)
        {
            ans[0] = x;
            break;
        }
        for (auto i : mat[x])
        {
            if (!vis[i])
            {
                vis[i] = 1;
                q.push(i);
            }
        }
    }
    // D > B
    if (ans[1] > ans[3])
    {
        int temp = ans[1];
        ans[1] = ans[3];
        ans[3] = temp;
    }
    for (int i = 0; i < 6; i++)
        cout << ans[i] << ' ';
}

void input()
{
    cin >> n;
    for (int i = 0; i < n + 3; i++)
    {
        int u, v;
        cin >> u >> v;
        mat[u].push_back(v);
        mat[v].push_back(u);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}