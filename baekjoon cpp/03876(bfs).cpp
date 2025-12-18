#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, string> m;
unordered_map<string, bool> vis;
string a, b;

void solve()
{
    queue<pair<string, int>> q;
    q.push({a, 0});
    vis[a] = 1;
    int blen = b.length();
    while (q.size())
    {
        string s = q.front().first;
        int cnt = q.front().second;
        q.pop();
        if (s == b)
        {
            cout << cnt << '\n';
            return;
        }
        int slen = s.length();
        if (slen > blen)
            continue;
        for (auto i : m)
        {
            string f = i.first;
            string k = i.second;
            string ss = s;
            slen = s.length();
            for (int j = 0; j < slen; j++)
            {
                for (int p = 1; p <= slen - j; p++)
                {
                    string t = ss.substr(j, p);
                    if (t == f)
                    {
                        ss.erase(j, p);
                        ss.insert(j, k);
                        int dif = k.size();
                        j += dif - 1;
                        slen = ss.length();
                        break;
                    }
                }
            }
            if (vis[ss])
                continue;
            vis[ss] = 1;
            q.push({ss, cnt + 1});
        }
    }
    cout << -1 << '\n';
}

void input()
{
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            string x, y;
            cin >> x >> y;
            m.insert({x, y});
        }
        cin >> a >> b;
        solve();
        m.clear();
        vis.clear();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}