#include <bits/stdc++.h>
using namespace std;

int n;
vector<string> ma;
vector<string> v;
vector<string> k = {
    "ABC",
    "DEF",
    "GHI",
    "JKL",
    "MNO",
    "PQRS",
    "TUV",
    "WXYZ"};

void solve()
{
    int t;
    cin >> t;
    queue<int> q;
    for (int i = 0; i < t; i++)
    {
        int a;
        cin >> a;
        if (a != 1)
            q.push(a);
        else
        {
            string s = "";
            while (q.size())
            {
                s += q.front() + '0';
                q.pop();
            }
            vector<string> ans;
            for (int j = 0; j < ma.size(); j++)
            {
                if (ma[j] == s)
                    ans.push_back(v[j]);
            }
            if (ans.empty())
            {
                for (int k = 0; k < s.length(); k++)
                    cout << "*";
            }
            else
            {
                sort(ans.begin(), ans.end());
                cout << ans[0];
            }
            cout << ' ';
        }
    }
    string s = "";
    while (q.size())
    {
        s += q.front() + '0';
        q.pop();
    }
    vector<string> ans;
    for (int j = 0; j < ma.size(); j++)
    {
        if (ma[j] == s)
            ans.push_back(v[j]);
    }
    if (ans.empty())
    {
        for (int k = 0; k < s.length(); k++)
            cout << "*";
    }
    else
    {
        sort(ans.begin(), ans.end());
        cout << ans[0];
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        int len = s.length();
        string t = "";
        for (int j = 0; j < len; j++)
        {
            bool brk = 0;
            for (int y = 0; y < 8; y++)
            {
                for (auto z : k[y])
                {
                    if (z == s[j])
                    {
                        t += '0' + y + 2;
                        brk = 1;
                        break;
                    }
                }
                if (brk)
                    break;
            }
        }
        v.push_back(s);
        ma.push_back(t);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}