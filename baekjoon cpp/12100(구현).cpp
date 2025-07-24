#include <bits/stdc++.h>
using namespace std;

int n, mat[21][21], ans;

void bt(int t)
{
    if (t == 5)
    {
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                ans = max(ans, mat[i][j]);
        return;
    }

    int tmp[21][21];
    // UP
    memcpy(tmp, mat, sizeof(mat));
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
                continue;
            for (int k = i + 1; k < n; k++)
            {
                if (mat[k][j] > 0)
                {
                    if (mat[k][j] == mat[i][j])
                    {
                        mat[i][j] *= 2;
                        mat[k][j] = 0;
                    }
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                for (int k = i + 1; k < n; k++)
                {
                    if (mat[k][j] > 0)
                    {
                        mat[i][j] = mat[k][j];
                        mat[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
    bool changed = 0;
    for (int i = 0; i < n && !changed; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != tmp[i][j])
            {
                changed = 1;
                break;
            }
        }
    }
    if (changed)
        bt(t + 1);
    memcpy(mat, tmp, sizeof(mat));

    // LEFT
    memcpy(tmp, mat, sizeof(mat));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (mat[i][j] == 0)
                continue;
            for (int k = j + 1; k < n; k++)
            {
                if (mat[i][k] > 0)
                {
                    if (mat[i][k] == mat[i][j])
                    {
                        mat[i][j] *= 2;
                        mat[i][k] = 0;
                    }
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - 1; j++)
        {
            if (mat[i][j] == 0)
            {
                for (int k = j + 1; k < n; k++)
                {
                    if (mat[i][k] > 0)
                    {
                        mat[i][j] = mat[i][k];
                        mat[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
    changed = 0;
    for (int i = 0; i < n && !changed; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != tmp[i][j])
            {
                changed = 1;
                break;
            }
        }
    }
    if (changed)
        bt(t + 1);
    memcpy(mat, tmp, sizeof(mat));

    // RIGHT
    memcpy(tmp, mat, sizeof(mat));
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > 0; j--)
        {
            if (mat[i][j] == 0)
                continue;
            for (int k = j - 1; k >= 0; k--)
            {
                if (mat[i][k] > 0)
                {
                    if (mat[i][k] == mat[i][j])
                    {
                        mat[i][j] *= 2;
                        mat[i][k] = 0;
                    }
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = n - 1; j > 0; j--)
        {
            if (mat[i][j] == 0)
            {
                for (int k = j - 1; k >= 0; k--)
                {
                    if (mat[i][k] > 0)
                    {
                        mat[i][j] = mat[i][k];
                        mat[i][k] = 0;
                        break;
                    }
                }
            }
        }
    }
    changed = 0;
    for (int i = 0; i < n && !changed; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != tmp[i][j])
            {
                changed = 1;
                break;
            }
        }
    }
    if (changed)
        bt(t + 1);
    memcpy(mat, tmp, sizeof(mat));

    // DOWN
    memcpy(tmp, mat, sizeof(mat));
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
                continue;
            for (int k = i - 1; k >= 0; k--)
            {
                if (mat[k][j] > 0)
                {
                    if (mat[k][j] == mat[i][j])
                    {
                        mat[i][j] *= 2;
                        mat[k][j] = 0;
                    }
                    break;
                }
            }
        }
    }
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                for (int k = i - 1; k >= 0; k--)
                {
                    if (mat[k][j] > 0)
                    {
                        mat[i][j] = mat[k][j];
                        mat[k][j] = 0;
                        break;
                    }
                }
            }
        }
    }
    changed = 0;
    for (int i = 0; i < n && !changed; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] != tmp[i][j])
            {
                changed = 1;
                break;
            }
        }
    }
    if (changed)
        bt(t + 1);
    memcpy(mat, tmp, sizeof(mat));
}

void solve()
{
    bt(0);
    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mat[i][j];
            ans = max(ans, mat[i][j]);
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