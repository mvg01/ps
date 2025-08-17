#include <bits/stdc++.h>
using namespace std;

char mat[5][5];
int d[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};
int ans = 0;
vector<pair<int, int>> v;

void bfs()
{
    bool vis[5][5];
    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            vis[i][j] = 1;
        }
    }
    for (auto i : v)
    {
        vis[i.first][i.second] = 0;
    }
    int cnt = 1;
    queue<pair<int, int>> q;
    vis[v[0].first][v[0].second] = 1;
    q.push({v[0].first, v[0].second});
    while (q.size())
    {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (cnt == 7)
        {
            ans++;
            return;
        }
        for (int i = 0; i < 4; i++)
        {
            int yy = y + d[i][0];
            int xx = x + d[i][1];
            if (yy >= 5 || yy < 0 || xx >= 5 || xx < 0)
                continue;
            if (!vis[yy][xx])
            {
                vis[yy][xx] = 1;
                q.push({yy, xx});
                cnt++;
            }
        }
    }
}

void f(int s, int cnt)
{ // 무작위 25C7 자리 백트래킹
    if (v.size() == 7)
    {
        if (cnt >= 4)
        {
            bfs(); // 연결 여부 확인
        }
        return;
    }
    for (int i = s; i < 25; i++)
    {
        int y = i / 5;
        int x = i % 5;
        int p = cnt;
        if (mat[y][x] == 'S')
            p++;
        v.push_back({y, x});
        f(i + 1, p);
        v.pop_back();
    }
}

void solve()
{
    f(0, 0);
    cout << ans;
}

void input()
{
    for (int i = 0; i < 5; i++)
        cin >> mat[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}