#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int y, x, idx, d;
} shark;

int n, m, k, ans = 0;
shark l[401];
vector<shark> v;
int p[401][4][4];
int mat[21][21], smell[21][21];
int d[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve()
{
    while (1)
    {
        if (v.size() == 1) // 남은 상어 1마리
        {
            cout << ans;
            return;
        }
        if (ans == 1000)
        {
            cout << -1;
            return;
        }
        vector<shark> temp[21][21];
        for (int i = 0; i < v.size(); i++)
        {
            int y = v[i].y;
            int x = v[i].x;
            int idx = v[i].idx;
            int dir = v[i].d;
            shark s;
            bool chk = 0;
            for (int j = 0; j < 4; j++)
            { // 방향에 따른 우선순위 4가지 / 빈 공간 찾아서
                int yy = y + d[p[idx][dir][j]][0];
                int xx = x + d[p[idx][dir][j]][1];
                if (yy >= n || yy < 0 || xx >= n || xx < 0)
                    continue;
                if (mat[yy][xx] == -1)
                {
                    s.y = yy;
                    s.x = xx;
                    s.idx = idx;
                    s.d = p[idx][dir][j];
                    temp[yy][xx].push_back(s);
                    chk = 1;
                    break;
                }
            }
            if (!chk)
            { // 빈 공간이 없다면 자기 자신의 칸으로 돌아감
                for (int j = 0; j < 4; j++)
                { // 방향에 따른 우선순위 4가지
                    int yy = y + d[p[idx][dir][j]][0];
                    int xx = x + d[p[idx][dir][j]][1];
                    if (yy >= n || yy < 0 || xx >= n || xx < 0)
                        continue;
                    if (mat[yy][xx] == idx)
                    {
                        s.y = yy;
                        s.x = xx;
                        s.idx = idx;
                        s.d = p[idx][dir][j];
                        temp[yy][xx].push_back(s);
                        break;
                    }
                }
            }
        }
        for (int i = 0; i < n; i++) // 냄새와 자리 계산
        {
            for (int j = 0; j < n; j++)
            {
                if (smell[i][j] != 0)
                {
                    smell[i][j]--;
                    if (smell[i][j] == 0)
                        mat[i][j] = -1;
                }
            }
        }
        v.clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (temp[i][j].size() > 1)
                {
                    int mn = 1e9, save = 0;
                    for (int q = 0; q < temp[i][j].size(); q++)
                    {
                        if (mn > temp[i][j][q].idx)
                        {
                            mn = temp[i][j][q].idx;
                            save = q;
                        }
                    }
                    v.push_back(temp[i][j][save]);
                    mat[i][j] = temp[i][j][save].idx;
                    smell[i][j] = k;
                }
                else if (temp[i][j].size() == 1)
                {
                    v.push_back(temp[i][j][0]);
                    mat[i][j] = temp[i][j][0].idx;
                    smell[i][j] = k;
                }
            }
        }
        ans++;
    }
}

void input()
{
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int idx;
            cin >> idx;
            idx--;
            if (idx != -1)
            {
                shark s;
                s.y = i;
                s.x = j;
                s.idx = idx;
                l[idx] = s;
                mat[i][j] = idx;
                smell[i][j] = k;
            }
            else
                mat[i][j] = -1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> l[i].d;
        l[i].d--;
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                cin >> p[i][j][k];
                p[i][j][k]--;
            }
        }
    }
    for (int i = 0; i < m; i++)
        v.push_back(l[i]);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}