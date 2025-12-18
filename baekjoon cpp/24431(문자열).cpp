#include <bits/stdc++.h>
using namespace std;

int t, n, l, f;
string s[501];

int solve()
{
    int ans = 0;
    map<string, int> m;
    for (int i = 0; i < n; i++)
    {
        string t = s[i].substr(l - f, f);
        m[t]++;
    }
    for (auto i : m)
    {
        if (i.second > 0)
            ans += i.second / 2;
    }
    return ans;
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> l >> f;
        for (int i = 0; i < n; i++)
            cin >> s[i];
        cout << solve() << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}