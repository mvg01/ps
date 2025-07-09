#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, string>> v;
vector<string> ans[4];

void solve()
{
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i += 4)
    {
        for (int j = 0; j < 4; j++)
            ans[j].push_back(v[i + j].second);
    }
    for (int i = 0; i < 4; i++)
        sort(ans[i].begin(), ans[i].end());
    for (int i = 0; i < 4; i++)
    {
        cout << i + 1 << ' ';
        for (auto j : ans[i])
            cout << j << ' ';
        cout << '\n';
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        string s;
        cin >> s >> a;
        v.push_back({a, s});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}