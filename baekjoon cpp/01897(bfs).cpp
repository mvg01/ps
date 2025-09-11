#include <bits/stdc++.h>
using namespace std;

int d, mx;
string s, ans;
queue<string> q;
unordered_map<string, bool> m;

void solve()
{
    q.push(s);
    while (q.size())
    {
        string t = q.front();
        q.pop();
        if (mx < t.length())
        {
            ans = t;
            mx = t.length();
        }
        int len = t.length();
        for (int i = 0; i < len + 1; i++)
        {
            for (char j = 'a'; j <= 'z'; j++)
            {
                string temp = t.substr(0, i) + j + t.substr(i);
                if (m[temp])
                {
                    q.push(temp);
                    m.erase(temp);
                }
            }
        }
    }
    cout << ans;
}

void input()
{
    cin >> d >> s;
    for (int i = 0; i < d; i++)
    {
        string t;
        cin >> t;
        m[t] = 1;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}