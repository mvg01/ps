#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, p, s[10], ans[10];
int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
char mat[1001][1001];
bool vis[1001][1001];
queue<tuple<int, int, int, int>> q[10];

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] >= '1' && mat[i][j] <= p + '0')
            {
                q[mat[i][j] - '0'].push({i, j, 1, 0}); //  y / x / 1턴 / 0번 이동
                vis[i][j] = 1;
                ans[mat[i][j] - '0']++;
            }
        }
    }
    while (1)
    {
        bool brk = 0;
        for (int i = 1; i <= p; i++)
        {
            stack<tuple<int, int, int, int>> st;
            while (q[i].size())
            {
                int y = get<0>(q[i].front());
                int x = get<1>(q[i].front());
                int t = get<2>(q[i].front());
                int c = get<3>(q[i].front());
                q[i].pop();
                for (int k = 0; k < 4; k++)
                {
                    int yy = d[k][0] + y;
                    int xx = d[k][1] + x;
                    if (yy >= n || yy < 0 || xx >= m || xx < 0)
                        continue;
                    if (vis[yy][xx])
                        continue;
                    if (mat[yy][xx] == '.')
                    {
                        if (c + 1 == s[i - 1])
                        {
                            vis[yy][xx] = 1;
                            // q[i].push({ yy,xx,t + 1,0 });
                            st.push({yy, xx, t + 1, 0});
                        }
                        else
                        {
                            vis[yy][xx] = 1;
                            q[i].push({yy, xx, t, c + 1});
                        }
                        ans[i]++;
                        brk = 1;
                    }
                }
            }
            while (st.size())
            {
                q[i].push(st.top());
                st.pop();
            }
        }
        if (!brk)
            break;
    }
    for (int i = 1; i <= p; i++)
        cout << ans[i] << ' ';
}

void input()
{
    cin >> n >> m >> p;
    for (int i = 0; i < p; i++)
        cin >> s[i];
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