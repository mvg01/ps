#include <bits/stdc++.h>
using namespace std;

int j, a, ans;
char m[1000001];

void solve()
{
    cout << ans;
}

void input()
{
    cin >> j >> a;
    for (int i = 1; i <= j; i++)
        cin >> m[i];
    for (int i = 0; i < a; i++)
    {
        char x;
        int n;
        cin >> x >> n;
        if (x == 'L' && m[n] == 'L')
        {
            ans++;
            m[n] = '.';
        }
        else if (x == 'M')
        {
            if (m[n] == 'L' || m[n] == 'M')
            {
                ans++;
                m[n] = '.';
            }
        }
        else if (x == 'S')
        {
            if (m[n] == 'L' || m[n] == 'M' || m[n] == 'S')
            {
                ans++;
                m[n] = '.';
            }
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