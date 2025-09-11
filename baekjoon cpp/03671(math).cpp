#include <bits/stdc++.h>
using namespace std;

int c, a[10000001], len;
string s;
set<int> vis;
bool chk[10];

void f()
{
    for (int i = 1; i < 10000000; i++)
        a[i] = i;
    for (int i = 2; i <= sqrt(10000000); i++)
    {
        if (a[i] == 0)
            continue;
        for (int j = i * i; j < 10000000; j += i)
            a[j] = 0;
    }
    a[1] = 0;
}

void dfs(string k)
{
    if (!k.empty())
    {
        int t = stoi(k);
        if (a[t] != 0 && t <= 9999999)
        {
            vis.insert(t);
        }
    }
    for (int i = 0; i < len; i++)
    {
        if (!chk[i])
        {
            chk[i] = 1;
            dfs(k + s[i]);
            chk[i] = 0;
        }
    }
}

void solve()
{
    len = s.length();
    dfs("");
    cout << vis.size() << '\n';
}

void input()
{
    cin >> c;
    f();
    while (c--)
    {
        cin >> s;
        solve();
        vis.clear();
        for (int i = 0; i < 10; i++)
            chk[i] = 0;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}