#include <bits/stdc++.h>
using namespace std;

string s;
void solve()
{
    int len = s.length(), ans = 0;
    for (int i = 0; i < len - 1; i++)
    {
        if (s[i] == s[i + 1])
            ans++;
    }
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