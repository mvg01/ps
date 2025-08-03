#include <bits/stdc++.h>
using namespace std;

int n;
string s;
void solve()
{
    int len = s.length();
    if (s[0] == 'B' || s[len - 1] == 'A')
    {
        cout << "No";
        return;
    }
    cout << "Yes";
}

void input()
{
    cin >> n >> s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}