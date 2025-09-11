#include <bits/stdc++.h>
using namespace std;

int n, m, mat[101][101], idx = 1;
int vis[101][101], d[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
int par[7];
vector<tuple<int, int, int>> v;

int get_par(int x)
{
    if (x == par[x])
        return x;
    else
        return par[x] = get_par(par[x]);
}

void set_union(int a, int b)
{
    a = get_par(a);
    b = get_par(b);
    if (a != b)
        par[b] = a;
}

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    vis[y][x] = idx;
    q.push({y, x});
    while (q.size())
    {
        y = q.front().first;
        x = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                continue;
            if (vis[yy][xx])
                continue;
            if (mat[yy][xx] == 1)
            {
                vis[yy][xx] = idx;
                q.push({yy, xx});
            }
        }
    }
    idx++;
}

void connect(int y, int x)
{
    for (int i = 0; i < 4; i++)
    {
        int ty = y;
        int tx = x;
        int go = 0;
        while (1)
        {
            int yy = ty + d[i][0];
            int xx = tx + d[i][1];
            if (vis[yy][xx] == vis[y][x])
                break;
            if (yy >= n || yy < 0 || xx >= m || xx < 0)
                break;
            if (vis[yy][xx] != 0)
            {
                if (go > 1)
                    v.push_back({go, vis[y][x], vis[yy][xx]});
                break;
            }
            go++;
            ty = yy;
            tx = xx;
        }
    }
}

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1 && !vis[i][j])
                bfs(i, j); // 섬 인덱스로 분류
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] > 0)
                connect(i, j);
        }
    }
    for (int i = 0; i < 7; i++)
        par[i] = i;
    sort(v.begin(), v.end());
    int ans = 0, con = 0;
    for (int i = 0; i < v.size(); i++)
    {
        if (get_par(get<1>(v[i])) != get_par(get<2>(v[i])))
        {
            set_union(get<1>(v[i]), get<2>(v[i]));
            con++;
            ans += get<0>(v[i]);
        }
        if (con == idx - 2)
            break;
    }
    if (con == idx - 2)
        cout << ans;
    else
        cout << -1;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}