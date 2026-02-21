#include <bits/stdc++.h>
using namespace std;

int n, m, k, ans;
map<string, int> mp;

void solve()
{
    for (auto i : mp)
    {
        int cnt = 0;
        for (auto j : i.first)
        {
            if (j == '0')
                cnt++;
        }
        if (cnt > k)
            continue;
        if (cnt % 2 == k % 2)
            ans = max(ans, i.second);
    }
    cout << ans;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        mp[s]++;
    }
    cin >> k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}