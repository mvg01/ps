#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, k, a[4], b[4];
int mat[501][501];
bool vis[501][501];
ll res;
int d[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

void bfs(int y, int x)
{
    ll cnt = 0, my = 0; // 너의 위치 개수, 나의 위치 개수
    queue<pair<int, int>> q;
    q.push({y, x});
    vis[y][x] = 1;
    while (q.size())
    {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        if (mat[yy][xx] == 1) // 나의 영역 중 하나라면
            my++;
        else if (mat[yy][xx] == 2) // 너의 영역
            cnt++;
        else if (mat[yy][xx] == 3)
        { // 겹치는 영역
            my++;
            cnt++;
        }
        for (int i = 0; i < 4; i++)
        {
            int dy = yy + d[i][0];
            int dx = xx + d[i][1];
            if (dy > m || dy < 1 || dx > n || dx < 1)
                continue;
            if (mat[dy][dx] == 4) // 별의 위치라서 갈 수 없음
                continue;
            if (vis[dy][dx])
                continue;
            vis[dy][dx] = 1;
            q.push({dy, dx});
        }
    }
    res += cnt * my;
}

void solve()
{
    for (int i = a[0]; i <= a[1]; i++)
    {
        for (int j = b[0]; j <= b[1]; j++)
        {
            if (mat[j][i] == 4)
                continue;
            mat[j][i] = 1;
        }
    }
    for (int i = a[2]; i <= a[3]; i++)
    {
        for (int j = b[2]; j <= b[3]; j++)
        {
            if (mat[j][i] == 4)
                continue;
            else if (mat[j][i] == 1)
                mat[j][i] = 3;
            else
                mat[j][i] = 2;
        }
    }
    for (int i = a[0]; i <= a[1]; i++)
    {
        for (int j = b[0]; j <= b[1]; j++)
        {
            if (mat[j][i] == 4)
                continue;
            if (vis[j][i])
                continue;
            bfs(j, i);
        }
    }
    cout << res;
}

void input()
{
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int x, y;
        cin >> x >> y;
        mat[y][x] = 4;
    }
    for (int i = 0; i < 4; i++)
        cin >> a[i] >> b[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}