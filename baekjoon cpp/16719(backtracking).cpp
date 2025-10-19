#include <bits/stdc++.h>
using namespace std;

string s;
int len;
bool vis[101];

void f(int start, int end)
{
    if (start > end)
        return;
    int idx = -1;
    char mn = 'a';
    for (int i = start; i < end; i++)
    {
        if (s[i] < mn && !vis[i])
        {
            mn = s[i];
            idx = i;
        }
    }
    if (idx == -1)
        return;
    vis[idx] = 1;
    for (int i = 0; i < len; i++)
    {
        if (vis[i])
            cout << s[i];
    }
    cout << '\n';
    f(idx + 1, end);
    f(start, idx);
}

void solve()
{
    len = s.length();
    f(0, len);
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