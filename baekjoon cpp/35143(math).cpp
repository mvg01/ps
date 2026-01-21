#include <bits/stdc++.h>
using namespace std;
// 1, 121, 10201, 1002001, 100020001 ...
// 1^2, 11^2, 101^2, 1001^2, 10001^2 ...

int n;
void solve()
{
    if (n == 1)
    {
        cout << 1906;
        return;
    }
    if (n == 3)
    {
        cout << 2026;
        return;
    }
    string s = "1";
    for (int i = 0; i < n / 2 - 1; i++)
        s += "0";
    s += "2";
    for (int i = 0; i < n / 2 - 1; i++)
        s += "0";
    s += "1";
    string f = "1905";
    int idx = 3, left = 0;
    for (int i = s.length() - 1; i >= s.length() - 4; i--)
    {
        int t = (f[idx] - '0' + s[i] - '0') + left;
        if (t > 9)
            left = 1;
        else
            left = 0;
        s[i] = (t % 10) + '0';
        idx--;
    }
    if (left == 1)
        s[s.length() - 5] = s[s.length() - 5] + 1;
    cout << s;
}

void input()
{
    cin >> n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}