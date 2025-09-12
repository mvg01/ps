#include <bits/stdc++.h>
using namespace std;

int n, ans = 1;
string s;

void solve()
{
    stack<char> p;
    for (int i = 0; i < n; i++)
    {
        if (p.empty())
            p.push(s[i]);
        else
        {
            if (p.top() == '(' && s[i] == ')')
                p.pop();
            else if (p.top() == ')' && s[i] == '(')
                p.pop();
            else
            {
                p.push(s[i]);
                ans = max(ans, (int)p.size());
            }
        }
    }
    if (p.size())
        ans = -1;
    cout << ans;
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