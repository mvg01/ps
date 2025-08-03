#include <bits/stdc++.h>
using namespace std;

string s;
void solve()
{
    int len = s.length();
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '<')
        {
            if (i + 4 <= len && s.substr(i, 4) == "<div")
            {
                cout << "title : ";
                int j = i + 12;
                string txt = "";
                bool space = 0;
                while (j < len)
                {
                    if (!space || (s[j] != ' ' && space))
                        txt += s[j];
                    if (s[j] == ' ')
                        space = 1;
                    else
                        space = 0;
                    j++;
                    if (s[j] == '"')
                        break;
                }
                for (char k : txt)
                    cout << k;
                cout << '\n';
                i = j;
            }
            else if (i + 3 <= len && s.substr(i, 3) == "<p>")
            {
                int j = i + 3;
                string txt = "";
                bool chk = 0, space = 0;
                while (j < len)
                {
                    if (s.substr(j, 4) == "</p>")
                        break;
                    if (s[j] == '<')
                        chk = 1;
                    if (s[j] == '>')
                    {
                        chk = 0;
                        j++;
                        continue;
                    }
                    if (!chk && s[j] == ' ')
                    {
                        if (space)
                        {
                            j++;
                            continue;
                        }
                        space = 1;
                        txt += ' ';
                    }
                    else if (!chk)
                        space = 0;
                    if (!chk && !space)
                        txt += s[j];
                    j++;
                }
                if (txt[0] == ' ')
                    txt.erase(0, 1);
                if (txt[txt.length() - 1] == ' ')
                    txt.pop_back();
                for (char k : txt)
                    cout << k;
                cout << '\n';
                i = j;
            }
        }
    }
}

void input()
{
    getline(cin, s);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}