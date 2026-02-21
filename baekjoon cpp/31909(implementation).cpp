#include <bits/stdc++.h>
using namespace std;

int n, x[200001], k, ans[8];
int d[9] = {1, 2, 4, 8, 16, 32, 64, 128, 256};
void solve()
{
    for (int i = 0; i < 8; i++)
        ans[i] = i;
    for (int i = 0; i < n; i++)
    {
        bool chk = 0;
        int a, b;
        for (int j = 0; j < 8; j++)
        {
            for (int z = j + 1; z < 9; z++)
            {
                if (d[j] + d[z] == x[i])
                {
                    chk = 1;
                    a = j;
                    b = z;
                    break;
                }
            }
            if (chk)
                break;
        }
        if (chk)
            swap(ans[a], ans[b]);
    }
    cout << ans[k];
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    cin >> k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}