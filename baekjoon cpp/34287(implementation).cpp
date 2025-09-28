#include <bits/stdc++.h>
using namespace std;

string s;
int n;
vector<pair<string, string>> v;

void solve()
{
    int cnt = 0;
    while (1)
    {
        if (cnt >= 5000)
        {
            bool t = 0;
            for (int i = 0; i < n; i++)
            {
                if (s.find(v[i].first) != string::npos)
                {
                    t = 1;
                    break;
                }
            }
            if (t)
            {
                cout << "Time Limit Exceeded";
                return;
            }
        }
        bool chk = 0;
        for (int i = 0; i < n; i++)
        {
            int pos = s.find(v[i].first);
            if (pos != string::npos)
            {
                s.replace(pos, v[i].first.length(), v[i].second);
                chk = 1;
                if (s.length() > 255)
                {
                    cout << "Memory Limit Exceeded";
                    return;
                }
                break;
            }
        }
        if (!chk)
        {
            cout << s;
            return;
        }
        cnt++;
    }
}

void input()
{
    cin >> s >> n;
    for (int i = 0; i < n; i++)
    {
        string t, a, b;
        cin >> t;
        int len = t.length();
        bool chk = 0;
        for (int j = 0; j < len; j++)
        {
            if (t[j] == '=')
            {
                chk = 1;
                continue;
            }
            if (!chk)
                a += t[j];
            else
                b += t[j];
        }
        v.push_back({a, b});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}