#include <bits/stdc++.h>
using namespace std;

int n, m;
double a[100001], ans;

void solve()
{
    deque<pair<int, double>> d;
    for (int i = 0; i < n; i++)
    {
        if (d.empty())
        {
            d.push_back({i, a[i]});
        }
        else
        {
            while (d.size() && d.back().second > a[i])
            {
                d.pop_back();
            }
            d.push_back({i, a[i]});
            if (d.front().first <= i - m)
                d.pop_front();
            ans = max(ans, d.back().second - d.front().second);
        }
    }
    cout << ans;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(6);
    cout << fixed;
    input();
    solve();
}