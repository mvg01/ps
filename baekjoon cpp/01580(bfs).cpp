#include <bits/stdc++.h>
using namespace std;

int n, m, ax, ay, bx, by;
char mat[21][21];
int vis[21][21][21][21];
int d[9][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {0, 0}};

void solve()
{
    queue<tuple<int, int, int, int>> q;
    q.push({ay, ax, by, bx});
    vis[ay][ax][by][bx] = 1;
    while (q.size())
    {
        int Ay = get<0>(q.front());
        int Ax = get<1>(q.front());
        int By = get<2>(q.front());
        int Bx = get<3>(q.front());
        q.pop();
        if (Ay == by && Ax == bx && By == ay && Bx == ax)
        {
            cout << vis[Ay][Ax][By][Bx] - 1;
            return;
        }
        for (int i = 0; i < 9; i++)
        {
            int ayy = Ay + d[i][0];
            int axx = Ax + d[i][1];
            if (ayy >= n || ayy < 0 || axx >= m || axx < 0)
                continue;
            if (mat[ayy][axx] == 'X')
                continue;
            for (int j = 0; j < 9; j++)
            {
                int byy = By + d[j][0];
                int bxx = Bx + d[j][1];
                if (byy >= n || byy < 0 || bxx >= m || bxx < 0)
                    continue;
                if (mat[byy][bxx] == 'X')
                    continue;
                if (vis[ayy][axx][byy][bxx])
                    continue;
                if (ayy == By && axx == Bx && byy == Ay && bxx == Ax) // 교차불가
                    continue;
                if (ayy == byy && axx == bxx) // 같은곳에 있을 수 없음
                    continue;
                q.push({ayy, axx, byy, bxx});
                vis[ayy][axx][byy][bxx] = vis[Ay][Ax][By][Bx] + 1;
            }
        }
    }
    cout << -1;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> mat[i];
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 'A')
            {
                ax = j;
                ay = i;
            }
            if (mat[i][j] == 'B')
            {
                bx = j;
                by = i;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}