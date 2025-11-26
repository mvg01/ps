#include <bits/stdc++.h>
using namespace std;

int n, m;
char mat[1001][1001];

void solve()
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < m - 1; j++)
        {
            if (mat[i][j] == '1')
            {
                if (mat[i][j + 1] == '1' && mat[i + 1][j] == '1' && mat[i + 1][j + 1] == '1')
                {
                    cout << 1;
                    return;
                }
            }
        }
    }
    cout << 0;
}
void input()
{
    cin >> n >> m;
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