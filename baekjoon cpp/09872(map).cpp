#include <bits/stdc++.h>
using namespace std;

int n;
map<vector<string>, int> m;
void solve()
{
    int ans = -1;
    for (auto i : m)
        ans = max(ans, i.second);
    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        vector<string> v;
        string s;
        for (int j = 0; j < 3; j++)
        {
            cin >> s;
            v.push_back(s);
        }
        sort(v.begin(), v.end());
        m[v]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}