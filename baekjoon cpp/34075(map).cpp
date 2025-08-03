#include <bits/stdc++.h>
using namespace std;

int n, m, q;
map<string, int> a, b;

void solve()
{
    string s, name;
    for (int i = 0; i < q; i++)
    {
        getline(cin, s);
        if (s == "nani ga suki?")
        {
            int p = b[name];
            vector<pair<int, string>> v;
            for (auto j : a)
                v.push_back({abs(j.second - p), j.first});
            sort(v.begin(), v.end());
            cout << v[1].second << " yori mo " << v[0].second << '\n';
        }
        else
        {
            name = "";
            int len = s.length();
            for (int j = 0; j < len; j++)
            {
                if (s[j] == ' ')
                    break;
                name += s[j];
            }
            cout << "hai!\n";
        }
    }
}

void input()
{
    string s;
    int x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> x;
        a[s] = x;
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> s >> x;
        b[s] = x;
    }
    cin >> q;
    cin.ignore();
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}