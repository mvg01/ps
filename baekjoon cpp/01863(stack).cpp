#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<pair<int, int>> v;
stack<int> s;

void solve()
{
    for (int i = 0; i < n; i++)
    {
        int y = v[i].second;
        if (s.empty() && y > 0)
        {
            s.push(y);
            continue;
        }
        if (s.empty())
            continue;

        if (y < s.top())
        {
            while (s.size())
            {
                if (y < s.top())
                {
                    s.pop();
                    ans++;
                }
                else
                    break;
            }
        }
        if (y > 0)
        {
            if (s.empty())
                s.push(y);
            else if (s.top() != y)
                s.push(y);
        }
    }
    while (s.size())
    {
        ans++;
        s.pop();
    }
    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v.push_back({x, y});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}