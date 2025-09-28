#include <bits/stdc++.h>
using namespace std;

int n, l, ans;
int mat[101][101];

void solve()
{
    for (int i = 0; i < n; i++)
    {
        bool chk = 0, vis[101] = {
                          0,
                      };
        for (int j = 0; j < n - 1; j++)
        {
            int dif = mat[i][j] - mat[i][j + 1];
            if (dif == 0)
                continue;
            if (abs(dif) > 1)
            {
                chk = 1;
                break;
            }
            if (dif == 1)
            { // 내리막길 가능한지  \ 모양
                if (j + l >= n)
                {
                    chk = 1;
                    break;
                }
                for (int k = j + 1; k < j + 1 + l; k++)
                {
                    if (mat[i][k] != mat[i][j] - 1 || vis[k])
                    {
                        chk = 1;
                        break;
                    }
                }
                if (chk)
                    break;
                for (int k = j + 1; k < j + 1 + l; k++)
                    vis[k] = 1;
            }
            else if (dif == -1)
            { // 오르막길 가능한지  / 모양
                if (j - l + 1 < 0)
                {
                    chk = 1;
                    break;
                }
                for (int k = j - l + 1; k <= j; k++)
                {
                    if (mat[i][k] != mat[i][j + 1] - 1 || vis[k])
                    {
                        chk = 1;
                        break;
                    }
                }
                if (chk)
                    break;
                for (int k = j - l + 1; k <= j; k++)
                    vis[k] = 1;
            }
        }
        if (!chk)
            ans++;
    }
    for (int i = 0; i < n; i++)
    {
        bool chk = 0, vis[101] = {
                          0,
                      };
        for (int j = 0; j < n - 1; j++)
        {
            int dif = mat[j][i] - mat[j + 1][i];
            if (dif == 0)
                continue;
            if (abs(dif) > 1)
            {
                chk = 1;
                break;
            }
            if (dif == 1)
            { // 내리막길 가능한지 \ 모양
                if (j + l >= n)
                {
                    chk = 1;
                    break;
                }
                for (int k = j + 1; k <= j + l; k++)
                {
                    if (mat[k][i] != mat[j][i] - 1 || vis[k])
                    {
                        chk = 1;
                        break;
                    }
                }
                if (chk)
                    break;
                for (int k = j + 1; k <= j + l; k++)
                    vis[k] = 1;
            }
            else if (dif == -1)
            { // 오르막길 가능한지 / 모양
                if (j - l + 1 < 0)
                {
                    chk = 1;
                    break;
                }
                for (int k = j - l + 1; k <= j; k++)
                {
                    if (mat[k][i] != mat[j + 1][i] - 1 || vis[k])
                    {
                        chk = 1;
                        break;
                    }
                }
                if (chk)
                    break;
                for (int k = j - l + 1; k <= j; k++)
                    vis[k] = 1;
            }
        }
        if (!chk)
            ans++;
    }
    cout << ans;
}

void input()
{
    cin >> n >> l;
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