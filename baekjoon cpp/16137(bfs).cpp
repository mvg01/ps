#include <bits/stdc++.h>
using namespace std;

int n, m, mat[11][11], ans = 1e9;
bool no[11][11];
bool vis[11][11][4000][2];
int d[5][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}, {0, 0}};
void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                int chk = 0;
                for (int k = 0; k < 2; k++)
                {
                    int y1 = i + d[k][0];
                    int x1 = j + d[k][1];
                    int y2 = i + d[k + 2][0];
                    int x2 = j + d[k + 2][1];
                    if (y1 >= n || y1 < 0 || x1 >= n || x1 < 0)
                        continue;
                    if (y2 >= n || y2 < 0 || x2 >= n || x2 < 0)
                        continue;
                    if (mat[y1][x1] != 1 && mat[y2][x2] != 1)
                        continue;
                    chk++;
                }
                if (chk == 2) // 오작교를 지을 수 없는 곳
                    no[i][j] = 1;
            }
        }
    }
    queue<tuple<int, int, int, bool, bool>> q;
    q.push({0, 0, 0, 0, 0});
    vis[0][0][0][0] = 1;
    while (q.size())
    {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        int k = get<2>(q.front());
        bool chk = get<3>(q.front());
        bool pre = get<4>(q.front());
        q.pop();
        if (y == n - 1 && x == n - 1)
        {
            ans = min(ans, k);
            continue;
        }
        if (k == 8000)
            continue;
        for (int i = 0; i < 5; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= n || yy < 0 || xx >= n || xx < 0)
                continue;
            if (vis[yy][xx][k + 1][chk])
                continue;
            if (no[yy][xx])
                continue;
            if (mat[yy][xx] == 1)
            {
                q.push({yy, xx, k + 1, chk, 0});
                vis[yy][xx][k + 1][chk] = 1;
            }
            if (pre)
                continue; // 이전 턴에 오작교를 건넘
            if (!chk)
            {
                if (mat[yy][xx] == 0 && (k + 1) % m == 0)
                {
                    q.push({yy, xx, k + 1, true, true});
                    vis[yy][xx][k + 1][1] = 1;
                }
            }
            if (mat[yy][xx] > 1 && (k + 1) % mat[yy][xx] == 0)
            {
                q.push({yy, xx, k + 1, chk, true});
                vis[yy][xx][k + 1][chk] = 1;
            }
        }
    }
    cout << ans;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
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