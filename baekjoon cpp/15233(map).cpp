#include <bits/stdc++.h>
using namespace std;

int a, b, g;
string s;
map<string, bool> aa, bb;

void solve()
{
}

void input()
{
    cin >> a >> b >> g;
    for (int i = 0; i < a; i++)
    {
        cin >> s;
        aa[s] = 1;
    }
    for (int i = 0; i < b; i++)
    {
        cin >> s;
        bb[s] = 1;
    }
    int x = 0, y = 0;
    for (int i = 0; i < g; i++)
    {
        cin >> s;
        if (aa.find(s) != aa.end())
            x++;
        if (bb.find(s) != bb.end())
            y++;
    }
    if (x > y)
        cout << "A";
    else if (x < y)
        cout << "B";
    else
        cout << "TIE";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}