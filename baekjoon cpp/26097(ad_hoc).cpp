#include <bits/stdc++.h>
using namespace std;

int n, m, mat[1001][1001], a, b, cnt;
vector<tuple<int, int, int, int>> ans;
vector<pair<int, int>> al, bl;
bool vis[1001][1001];
int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};

void solve()
{
    if (n * m % 2 == 1)
    {
        cout << -1;
        return;
    }
    bool find = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (!find)
                {
                    int y = i + d[k][0];
                    int x = j + d[k][1];
                    if (y >= n || y < 0 || x >= m || x < 0)
                        continue;
                    if (mat[y][x] == mat[i][j])
                    {
                        ans.push_back({y, x, i, j});
                        vis[y][x] = 1;
                        vis[i][j] = 1;
                        find = 1;
                        if (mat[i][j] == 1)
                            a += 2;
                        if (mat[i][j] == 0)
                            b += 2;
                        break;
                    }
                }
            }
            if (vis[i][j])
                continue;
            if (mat[i][j] == 1)
            {
                a++;
                al.push_back({i, j});
            }
            else
            {
                b++;
                bl.push_back({i, j});
            }
        }
    }
    if (a % 2 == 1 || b % 2 == 1 || !find)
    {
        cout << -1;
        return;
    }
    for (int i = 0; i < al.size(); i += 2)
    {
        ans.push_back({al[i].first, al[i].second, al[i + 1].first, al[i + 1].second});
    }
    for (int i = 0; i < bl.size(); i += 2)
    {
        ans.push_back({bl[i].first, bl[i].second, bl[i + 1].first, bl[i + 1].second});
    }
    cout << 1 << '\n';
    for (auto i : ans)
    {
        cout << get<0>(i) + 1 << ' ' << get<1>(i) + 1 << ' ' << get<2>(i) + 1 << ' ' << get<3>(i) + 1 << '\n';
    }
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