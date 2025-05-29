#include <bits/stdc++.h>
using namespace std;

int t, n, c = 1;
map<string, string> m;
set<string> e;
void solve()
{
    string s;
    for (auto i : m)
    {
        if (e.find(i.first) == e.end())
        {
            s = i.first;
            break;
        }
    }
    cout << "Case #" << c++ << ":";
    while (1)
    {
        if (m.find(s) == m.end())
            break;
        cout << ' ' << s << '-' << m[s];
        s = m[s];
    }
    cout << '\n';
    m.clear();
    e.clear();
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            string a, b;
            cin >> a >> b;
            m.insert({a, b});
            e.insert(b);
        }
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}