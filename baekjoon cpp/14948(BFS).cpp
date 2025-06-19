#include <bits/stdc++.h>
using namespace std;

int n, m, mat[101][101], ans = 1e9;
int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void solve()
{
    int start = 0, end = 1e9, mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        bool vis[101][101][2], clear = 0;
        for (int i = 0; i < 101; i++)
        {
            for (int j = 0; j < 101; j++)
            {
                vis[i][j][0] = 0;
                vis[i][j][1] = 0;
            }
        }
        queue<tuple<int, int, int>> q;
        if (mid >= mat[0][0])
        {
            q.push({0, 0, 0});
            vis[0][0][0] = 1;
            vis[0][0][1] = 1;
            while (q.size())
            {
                int y = get<0>(q.front());
                int x = get<1>(q.front());
                int chk = get<2>(q.front());
                q.pop();
                if (y == n - 1 && x == m - 1)
                {
                    clear = 1;
                    break;
                }
                for (int i = 0; i < 4; i++)
                {
                    int yy = y + d[i][0];
                    int xx = x + d[i][1];
                    if (yy >= n || yy < 0 || xx >= m || xx < 0)
                        continue;
                    if (mat[yy][xx] <= mid)
                    {
                        if (vis[yy][xx][chk])
                            continue;
                        q.push({yy, xx, chk});
                        vis[yy][xx][chk] = 1;
                    }
                    else if (!chk)
                    {
                        int ny = yy + d[i][0];
                        int nx = xx + d[i][1];
                        if (ny >= n || ny < 0 || nx >= m || nx < 0)
                            continue;
                        if (vis[ny][nx][1])
                            continue;
                        if (mat[ny][nx] <= mid)
                        {
                            q.push({ny, nx, 1});
                            vis[ny][nx][1] = 1;
                        }
                    }
                }
            }
        }
        if (clear)
        {
            end = mid - 1;
            ans = min(ans, mid);
        }
        else
            start = mid + 1;
    }
    cout << ans;
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

/*
도움이 된 반례

10 10
0 0 0 0 0 9 9 9 9 9
9 9 9 9 0 9 9 9 9 9
0 0 0 9 0 9 9 9 9 9
0 9 0 9 0 9 9 9 9 9
0 9 0 0 0 9 9 9 9 9
0 9 9 9 0 9 9 9 9 9
0 9 9 9 9 9 9 9 9 9
0 0 0 0 0 0 0 0 0 0
0 9 9 9 0 9 9 9 9 9
9 9 9 9 0 9 9 9 9 0
ans: 0   // 막판에 9 한번 건너 뛰어야 함

1 1
10
ans:10  // 시작점은 건너뛸 수 없어

1 2
4 3
ans: 4

5 6
5 5 5 5 7 100
7 7 7 7 5 7
7 7 7 7 5 7
7 7 7 7 5 7
7 7 7 7 5 5
ans: 7  //  2번 뛰어넘지 않게 체크

*/