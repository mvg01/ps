#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> v;

bool com(string a, string b)
{
    if (a.length() != b.length())
        return a.length() < b.length();
    return a < b;
}

void solve()
{
    sort(v.begin(), v.end(), com);
    vector<int> ans;
    for (int i = 0; i < min(n, 4); i++)
    {
        for (int j = 0; j < min(n, 4); j++)
        {
            if (i == j)
                continue;
            ans.push_back(stoi(v[i] + v[j]));
        }
    }
    sort(ans.begin(), ans.end());
    cout << ans[2];
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}