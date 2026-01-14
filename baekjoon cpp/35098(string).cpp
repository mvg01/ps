#include <bits/stdc++.h>
using namespace std;

int n;
string s;
void solve()
{
    cout << s;
    for (int i = 1; i < n; i++)
    {
        string sub1 = s.substr(i, n - i);
        string sub2 = s.substr(n - i, i);
        if (sub1 + sub2 == s)
        {
            cout << sub2 << '\n';
            return;
        }
    }
    cout << s << '\n';
}

void input()
{
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
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