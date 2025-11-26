#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<pair<int, int>> v;

bool com(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return 1;
    else if (a.first > b.first)
        return 0;
    else
    {
        return a.second > b.second;
    }
}

void solve()
{
    sort(v.begin(), v.end(), com);
    int t = 301;
    while (t <= 1130)
    {
        bool chk = 0;
        int idx = 0, end = t;
        while (idx < n && v[idx].first <= t)
        {
            if (end < v[idx].second)
            {
                chk = 1;
                end = v[idx].second;
            }
            idx++;
        }
        if (!chk)
        {
            cout << 0;
            return;
        }
        t = end;
        ans++;
    }
    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        v.push_back({a * 100 + b, c * 100 + d});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}