#include <bits/stdc++.h>
using namespace std;

int mat[4][18];
int com[18];
bool yes;

void bt(int a, int b, int cnt, int idx)
{
    if (cnt == 15)
    {
        for (int i = 0; i < 18; i++)
        {
            if (mat[idx][i] != com[i])
            {
                return;
            }
        }
        yes = 1;
        return;
    }
    if (b == 5)
    {
        com[a * 3]++;
        com[b * 3 + 2]++;
        bt(a + 1, a + 2, cnt + 1, idx);
        com[a * 3]--;
        com[b * 3 + 2]--;

        com[a * 3 + 1]++;
        com[b * 3 + 1]++;
        bt(a + 1, a + 2, cnt + 1, idx);
        com[a * 3 + 1]--;
        com[b * 3 + 1]--;

        com[a * 3 + 2]++;
        com[b * 3]++;
        bt(a + 1, a + 2, cnt + 1, idx);
        com[a * 3 + 2]--;
        com[b * 3]--;
    }
    else
    {
        com[a * 3]++;
        com[b * 3 + 2]++;
        bt(a, b + 1, cnt + 1, idx);
        com[a * 3]--;
        com[b * 3 + 2]--;

        com[a * 3 + 1]++;
        com[b * 3 + 1]++;
        bt(a, b + 1, cnt + 1, idx);
        com[a * 3 + 1]--;
        com[b * 3 + 1]--;

        com[a * 3 + 2]++;
        com[b * 3]++;
        bt(a, b + 1, cnt + 1, idx);
        com[a * 3 + 2]--;
        com[b * 3]--;
    }
}

void solve()
{
    for (int i = 0; i < 4; i++)
    {
        bt(0, 1, 0, i);
        if (yes)
            cout << "1 ";
        else
            cout << "0 ";
        yes = 0;
    }
}

void input()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 18; j++)
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