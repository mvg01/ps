#include <bits/stdc++.h>
using namespace std;

string s;
int cnt[26];
void solve()
{
    int len = s.length();
    bool odd = 0;
    if (len % 2 == 1)
        odd = 1;
    for (int i = 0; i < len; i++)
    {
        cnt[s[i] - 'a']++;
    }
    bool no = 0;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2 == 1)
        {
            if (!odd)
                no = 1;
            else
                odd = 0;
        }
    }
    if (no)
        cout << "no";
    else
        cout << "yes";
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