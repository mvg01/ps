#include <bits/stdc++.h>
using namespace std;

int n, m, k, s;
int d[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
int mat[501][501], ans[250001];
bool vis[501][501], vis2[250001];
vector<int> v[250001];

void bfs(int y, int x)
{
    int cnt = 1;
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> q;
    q.push({0, mat[y][x], y, x});
    vis[y][x] = 1;
    while (q.size())
    {
        int depth = get<0>(q.top());
        int num = get<1>(q.top());
        y = get<2>(q.top());
        x = get<3>(q.top());
        q.pop();
        for (int i = 0; i < 8; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (vis[yy][xx])
                continue;
            if (mat[yy][xx] != 0)
            {
                vis[yy][xx] = 1;
                v[num].push_back(mat[yy][xx]);
                v[mat[yy][xx]].push_back(num);
                q.push({depth + 1, mat[yy][xx], yy, xx});
                cnt++;
            }
        }
    }
    if (cnt != k)
    {
        cout << -1;
        exit(0);
    }
}

void maketree()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == s)
                bfs(i, j);
        }
    }
}

void dfs(int x)
{
    ans[x]++;
    if (v[x].size() == 1 && vis2[v[x][0]])
        return;
    for (int i = 0; i < v[x].size(); i++)
    {
        if (!vis2[v[x][i]])
        {
            vis2[v[x][i]] = 1;
            dfs(v[x][i]);
            ans[x] += ans[v[x][i]];
        }
    }
}

void solve()
{
    maketree();
    vis2[s] = 1;
    dfs(s);
    for (int i = 1; i <= k; i++)
        cout << ans[i] << ' ';
}

void input()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= k; i++)
    {
        int y, x;
        cin >> y >> x;
        y--;
        x--;
        mat[y][x] = i;
    }
    cin >> s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}