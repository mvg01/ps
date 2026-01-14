#include <bits/stdc++.h>
using namespace std;

string s;
int n;
vector<string> v;
bool dp[101];

void solve()
{
    for (int i = 0; i < s.length(); i++)
    {
        if (dp[i] || i == 0)
        {
            for (int j = 0; j < n; j++)
            {
                bool chk = 1;
                if (i + v[j].length() > s.length())
                    continue;
                for (int k = 0; k < v[j].length(); k++)
                {
                    if (s[i + k] != v[j][k])
                    {
                        chk = 0;
                        break;
                    }
                }
                if (chk)
                    dp[i + v[j].length()] = 1;
            }
        }
    }
    cout << dp[s.length()];
}

void input()
{
    cin >> s >> n;
    for (int i = 0; i < n; i++)
    {
        string y;
        cin >> y;
        v.push_back(y);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}