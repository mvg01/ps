#include <bits/stdc++.h>
using namespace std;

int n, m, cnt;
vector<int> v[100001];
bool vis[100001], cycle = 0, no = 0, over = 0;

void dfs(int s, int pre)
{
    if (v[s].size() > 3)
        no = 1;
    if (v[s].size() == 3)
    {
        if (over)
            no = 1;
        over = 1;
    }
    for (int i : v[s])
    {
        if (!vis[i])
        {
            vis[i] = 1;
            cnt++;
            dfs(i, s);
        }
        else if (i != pre)
            cycle = 1;
    }
}

void solve()
{
    if (n != m)
    {
        cout << "NO";
        return;
    }
    vis[1] = 1;
    cnt = 1;
    dfs(1, 0);
    if (no) // 사이클에 연결된 정점이 2개 이상
        cout << "NO";
    else if (cnt != n) // 모든 정점 연결 안됨
        cout << "NO";
    else if (cycle && over) // 사이클 1개 && 사이클 아닌 정점 연결
        cout << "YES";
    else
        cout << "NO";
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}