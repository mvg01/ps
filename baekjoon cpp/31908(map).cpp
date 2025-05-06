#include <bits/stdc++.h>
using namespace std;

int n, z = 0;
map<string, vector<string>> m;
vector<string> ans;
void solve()
{
    for (auto i : m)
    {
        if (i.second.size() == 2)
            z++;
    }
    cout << z << '\n';
    for (auto i : m)
    {
        if (i.second.size() == 2)
        {
            for (auto j : i.second)
                cout << j << ' ';
            cout << '\n';
        }
    }
}

void input()
{
    cin >> n;
    string s, x;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> x;
        if (x != "-")
            m[x].push_back(s);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}