#include <bits/stdc++.h>
using namespace std;

int n;
string s;

void solve()
{
    string temp = s;
    sort(s.begin(), s.end(), greater<char>());
    for (int i = 0; i < n; i++)
    {
        if (s[i] != temp[i])
        {
            vector<pair<string, int>> v;
            string t = "";
            for (int j = i; j < n; j++)
            {
                t += temp[j];
                reverse(t.begin(), t.end());
                v.push_back({t, j});
                reverse(t.begin(), t.end());
            }
            sort(v.begin(), v.end());
            // cout << v[v.size() - 1].first << '\n';
            int idx = v[v.size() - 1].second;
            cout << temp.substr(0, i) << v[v.size() - 1].first << temp.substr(idx + 1, n - 1 - idx);
            return;
        }
    }
    cout << s;
}

void input()
{
    cin >> n >> s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}