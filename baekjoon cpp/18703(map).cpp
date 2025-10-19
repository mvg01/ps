#include <bits/stdc++.h>
using namespace std;

int t;
map<string, int> m;

void solve()
{
}

void input()
{
    cin >> t;
    while (t--)
    {
        string s;
        int n, x;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cin >> s >> x;
            if (m.find(s) == m.end())
                m[s] = x;
            else
                m[s] = min(m[s], x);
        }
        vector<int> v;
        for (auto i : m)
            v.push_back(i.second);
        sort(v.begin(), v.end());
        for (int i = 0; i < v.size(); i++)
        {
            if (i != v.size() - 1)
                cout << v[i] << ' ';
            else
                cout << v[i];
        }
        cout << '\n';
        m.clear();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}