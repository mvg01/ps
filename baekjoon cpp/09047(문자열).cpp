#include <bits/stdc++.h>
using namespace std;

int t;
string s;
void solve()
{
    int idx = 0;
    while (1)
    {
        if (s == "6174")
        {
            cout << idx << '\n';
            return;
        }
        sort(s.begin(), s.end());
        int a = stoi(s);
        reverse(s.begin(), s.end());
        int b = stoi(s);
        string c = to_string(b - a);
        while (c.size() < 4)
            c = '0' + c;
        idx++;
        s = c;
    }
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> s;
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}