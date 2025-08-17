#include <bits/stdc++.h>
using namespace std;

int h, w, a[501], ans, mx;

void solve()
{
    stack<int> s;
    for (int i = 0; i < w; i++)
    {
        if (s.empty())
        {
            s.push(a[i]);
            mx = max(mx, a[i]);
            continue;
        }
        if (mx <= a[i])
        {
            while (!s.empty())
            {
                ans += mx - s.top();
                s.pop();
            }
            mx = a[i];
            s.push(a[i]);
        }
        else
        {
            s.push(a[i]);
        }
    }
    if (s.size())
    {
        mx = 0;
        while (s.size())
        {
            if (mx <= s.top())
            {
                mx = s.top();
                s.pop();
                continue;
            }
            ans += mx - s.top();
            s.pop();
        }
    }
    cout << ans;
}

void input()
{
    cin >> h >> w;
    for (int i = 0; i < w; i++)
        cin >> a[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}