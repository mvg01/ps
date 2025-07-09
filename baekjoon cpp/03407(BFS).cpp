#include <bits/stdc++.h>
using namespace std;

int n;
string s;
bool vis[50001];
unordered_map<string, bool> m;

void solve()
{
    int len = s.length();
    queue<int> q;
    string t = s.substr(0, 1);
    if (m[t])
    {
        q.push(1);
        vis[1] = 1;
    }
    if (len > 1)
    {
        t = s.substr(0, 2);
        if (m[t])
        {
            q.push(2);
            vis[2] = 1;
        }
    }
    while (q.size())
    {
        int c = q.front();
        q.pop();
        if (c == len)
        {
            cout << "YES\n";
            return;
        }
        if (len >= c + 1 && !vis[c + 1])
        {
            t = s.substr(c, 1);
            if (m[t])
            {
                q.push(c + 1);
                vis[c + 1] = 1;
            }
        }
        if (len >= c + 2)
        {
            if (vis[c + 2])
                continue;
            t = s.substr(c, 2);
            if (m[t])
            {
                q.push(c + 2);
                vis[c + 2] = 1;
            }
        }
    }
    cout << "NO\n";
}

void input()
{
    vector<string> es = {
        "h", "he", "li", "be", "b", "c", "n", "o", "f", "ne", "na", "mg", "al", "si", "p", "s", "cl", "ar", "k", "ca", "sc", "ti", "v", "cr", "mn", "fe", "co", "ni", "cu", "zn", "ga", "ge", "as", "se", "br", "kr", "rb", "sr", "y", "zr", "nb", "mo", "tc", "ru", "rh", "pd", "ag", "cd", "in", "sn", "sb", "te", "i", "xe", "cs", "ba", "hf", "ta", "w", "re", "os", "ir", "pt", "au", "hg", "tl", "pb", "bi", "po", "at", "rn", "fr", "ra", "rf", "db", "sg", "bh", "hs", "mt", "ds", "rg", "cn", "fl", "lv", "la", "ce", "pr", "nd", "pm", "sm", "eu", "gd", "tb", "dy", "ho", "er", "tm", "yb", "lu", "ac", "th", "pa", "u", "np", "pu", "am", "cm", "bk", "cf", "es", "fm", "md", "no", "lr"};
    for (auto e : es)
        m[e] = 1;
    cin >> n;
    while (n--)
    {
        cin >> s;
        solve();
        for (int i = 0; i < 50001; i++)
            vis[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}