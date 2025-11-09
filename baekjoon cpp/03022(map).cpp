#include <bits/stdc++.h>
using namespace std;

int n, ans;
map<string, int> m;

void solve()
{
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (m.find(s) == m.end())
            m.insert({s, 1});
        else
        {
            if (i - m[s] < m[s])
                ans++;
            m[s]++;
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