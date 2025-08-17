#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> ans;
bool vis[10001];

void solve()
{
    int temp = 0;
    for (int i = 2; i <= 16384; i *= 2)
    {
        if (n < i)
        {
            temp = i;
            break;
        }
    }
    for (int i = n; i >= 1; i--)
    {
        for (int j = temp; j >= 2; j /= 2)
        {
            if (i < j && j - i <= n)
            {
                if (!vis[j - i])
                {
                    vis[j - i] = 1;
                    ans.push_back(j - i);
                    break;
                }
            }
        }
    }
    reverse(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << '\n';
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