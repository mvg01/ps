#include <bits/stdc++.h>
using namespace std;

string s;
int v[300001], ans;
bool chk = 0, chk2 = 0;

void solve()
{
    int len = s.length();
    if (s == "+^+")
    {
        cout << 1;
        return;
    }
    else if (s == "-^-")
    {
        cout << 0;
        return;
    }
    if (s.find("-^-^-") != string::npos)
    {
        chk2 = 1;
    }
    for (int i = 0; i < len; i++)
    {
        if (i < len - 3)
        {
            string t = s.substr(i, 4);
            if (t == "+-^+" || t == "+^-+" || t == "+^^+")
                chk = 1;
            else if (t == "-+^-" || t == "-^+-" || t == "-^^-" || t == "-^-+" || t == "+-^-" || t == "-^-^" || t == "^-^-" || t == "-^--" || t == "--^-")
                chk = 1;
            if (t == "+^+-" || t == "+^+^" || t == "+^++")
                ans++;
            else if (t == "-^-+" || t == "-^-^" || t == "-^--")
                ans--;
        }
        else if (i == len - 3)
        {
            string t = s.substr(i, 3);
            if (t == "+^+")
                ans++;
            if (t == "-^-")
            {
                ans--;
                chk = 1;
            }
        }
    }
    if (chk2)
        ans += 2;
    else if (chk)
        ans++;
    cout << ans;
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