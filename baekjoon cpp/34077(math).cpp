#include <iostream>
#include <string>
#include <vector>

using namespace std;

void solve()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    bool chk = 0, ans = 0;
    for (int i = 1; i < 2 * n; i += 2)
    {
        if (chk && s[i + 1] != '0')
        {
            ans = 1;
            break;
        }
        if (s[i] == '-')
            chk = 1;
    }
    if (ans)
        cout << "NO\n";
    else
        cout << "YES\n";
}

void input()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}