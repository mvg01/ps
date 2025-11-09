#include <bits/stdc++.h>
using namespace std;

int n;
map<string, int> m;
set<string> ans;

void solve()
{
}

void input()
{
    while (cin >> n)
    {
        cin.ignore();
        string s;
        while (1)
        {
            getline(cin, s);
            if (s == "EndOfText")
                break;
            string temp = "";
            int len = s.length();
            for (int i = 0; i < len; i++)
            {
                if (isalpha(s[i]))
                    temp += tolower(s[i]);
                else
                {
                    if (!temp.empty())
                        m[temp]++;
                    temp = "";
                }
            }
            if (temp != "")
                m[temp]++;
        }
        bool chk = 0;
        for (auto i : m)
        {
            if (i.second == n)
            {
                ans.insert(i.first);
                chk = 1;
            }
        }
        if (!chk)
            cout << "There is no such word.\n";
        for (auto i : ans)
            cout << i << '\n';
        cout << '\n';
        m.clear();
        ans.clear();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}