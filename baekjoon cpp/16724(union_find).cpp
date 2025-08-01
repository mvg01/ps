#include <bits/stdc++.h>
using namespace std;

int n, m;
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
char mat[1001][1001];
int p[1000 * 1000];

void init()
{
    for (int i = 0; i < 1000000; i++)
        p[i] = i;
}

int get_parent(int x)
{
    if (x == p[x])
        return x;
    else
        return p[x] = get_parent(p[x]);
}

void set_union(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);
    if (a < b)
        p[b] = a;
    else
        p[a] = b;
}

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});
    while (q.size())
    {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        int dy, dx;
        if (mat[yy][xx] == 'U')
        {
            dy = yy + d[0][0];
            dx = xx + d[0][1];
        }
        if (mat[yy][xx] == 'D')
        {
            dy = yy + d[1][0];
            dx = xx + d[1][1];
        }
        if (mat[yy][xx] == 'L')
        {
            dy = yy + d[2][0];
            dx = xx + d[2][1];
        }
        if (mat[yy][xx] == 'R')
        {
            dy = yy + d[3][0];
            dx = xx + d[3][1];
        }
        if (dy >= n || dy < 0 || dx >= m || dx < 0)
            continue;
        int pre = yy * m + xx;
        int nxt = dy * m + dx;
        if (get_parent(pre) == get_parent(nxt))
            continue;
        q.push({dy, dx});
        set_union(pre, nxt);
    }
}

void solve()
{
    init();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            bfs(i, j);
    }
    set<int> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            s.insert(p[i * m + j]);
    }
    cout << s.size();
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}