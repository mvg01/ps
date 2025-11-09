#include <bits/stdc++.h>
using namespace std;

int n;
deque<string> v[101];
string q;

void solve()
{
    int len = q.length();
    string temp = "";
    for (int j = 0; j < len; j++)
    {
        if (q[j] == ' ')
        {
            bool chk = 0;
            for (int i = 0; i < n; i++)
            {
                if (!v[i].empty())
                {
                    if (temp == v[i].front())
                    {
                        v[i].pop_front();
                        chk = 1;
                        break;
                    }
                }
            }
            if (!chk)
            {
                cout << "Impossible";
                return;
            }
            temp = "";
        }
        else
            temp += q[j];
    }
    bool chk = 0;
    for (int i = 0; i < n; i++)
    {
        if (!v[i].empty())
        {
            if (temp == v[i].front())
            {
                v[i].pop_front();
                chk = 1;
                break;
            }
        }
    }
    if (!chk)
    {
        cout << "Impossible";
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (v[i].size())
        {
            cout << "Impossible";
            return;
        }
    }
    cout << "Possible";
}

void input()
{
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin, s);
        int len = s.length();
        string temp = "";
        for (int j = 0; j < len; j++)
        {
            if (s[j] == ' ')
            {
                v[i].push_back(temp);
                temp = "";
            }
            else
                temp += s[j];
        }
        v[i].push_back(temp);
    }
    getline(cin, q);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}