#include <bits/stdc++.h>
using namespace std;

int n, ans[1001];
void solve()
{
    for (int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            ans[i] |= x;
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