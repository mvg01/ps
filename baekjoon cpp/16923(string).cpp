#include <bits/stdc++.h>
using namespace std;

string s;
bool a[26];
void solve()
{
    int len = s.size();
    vector<string> v;
    v.push_back(s);
    for (int i = 0; i < len; i++)
    {
        a[s[i] - 'a'] = 1;
        string temp = s;
        string temp2 = s.substr(0, i + 1);
        for (int j = 0; j < 26; j++)
        {
            if (!a[j])
            {
                temp.insert(i + 1, 1, char('a' + j));
                temp2.insert(i + 1, 1, char('a' + j));
                if (temp != s)
                    v.push_back(temp);
                if (temp2 != s)
                    v.push_back(temp2);
                temp = s;
                temp2 = s.substr(0, i + 1);
            }
        }
    }
    sort(v.begin(), v.end());
    bool chk = 0;
    for (auto i : v)
    {
        if (chk)
        {
            bool vis[26] = {
                0,
            },
                 no = 0;
            for (auto j : i)
            {
                if (vis[j - 'a'])
                    no = 1;
                vis[j - 'a'] = 1;
            }
            if (!no)
            {
                cout << i;
                return;
            }
        }
        if (i == s)
            chk = 1;
    }
    cout << -1;
}

void input()
{
    cin >> s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}