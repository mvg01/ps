#include <bits/stdc++.h>
using namespace std;

int n, x, ans, sum;

void solve()
{
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char q;
        cin >> q >> x;
        if (q == 'T')
        {
            if (sum < x)
            {
                ans += x - sum;
                sum = 0;
            }
            else
                sum -= x;
        }
        else
        {
            sum += x;
        }
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}