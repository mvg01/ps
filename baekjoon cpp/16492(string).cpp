#include <bits/stdc++.h>
using namespace std;

map<char, string> g;
map<string, bool> d, vis;
string target = "";

void solve()
{
    string s = "A";
    for (int i = 0; i < 10; i++)
    {
        string x = "";
        int len = s.length();
        for (int j = 0; j < len; j++)
        {
            if (g.find(s[j]) != g.end())
                x += g[s[j]];
            else
                x += s[j];
        }
        len = x.length();
        vector<bool> unuse(len, false);
        for (int j = 0; j < len; j++)
        {
            for (int k = 2; k <= min(len - j, 5); k++)
            {
                string y = x.substr(j, k);
                if (d[y])
                {
                    for (int z = j; z < j + k; z++)
                        unuse[z] = 1;
                }
            }
        }
        string f = "";
        for (int i = 0; i < len; i++)
        {
            if (!unuse[i])
                f += x[i];
        }
        if (f == target)
        {
            cout << "O";
            return;
        }
        s = f;
    }
    cout << "X";
}

void input()
{
    while (1)
    {
        string s;
        getline(cin, s);
        int len = s.length();
        string temp = "";
        for (int i = 0; i < len; i++)
        {
            if (s[i] != ' ')
                temp += s[i];
            else
            {
                if (temp == "gen:")
                {
                    char a;
                    string b;
                    for (int j = 5; j < len; j++)
                    {
                        if (s[j] != ' ')
                            a = s[j];
                        else
                            break;
                    }
                    for (int j = 10; j < len; j++)
                    {
                        if (s[j] != ' ')
                            b += s[j];
                    }
                    g[a] = b;
                }
                else if (temp == "del:")
                {
                    string a;
                    for (int j = 5; j < len; j++)
                    {
                        if (s[j] != ' ')
                            a += s[j];
                    }
                    d[a] = 1;
                }
                else
                {
                    string a;
                    for (int j = 8; j < len; j++)
                    {
                        if (s[j] != ' ')
                            a += s[j];
                    }
                    target = a;
                }
                break;
            }
        }
        if (target != "")
            break;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}