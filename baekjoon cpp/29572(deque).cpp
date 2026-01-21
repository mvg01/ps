#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int m, k, c[100001], n[100001];
ll ans;

void solve()
{
    deque<pair<int, int>> d;
    for (int i = 0; i < m; i++)
    {
        if (d.empty())
        {
            d.push_back({i, c[i]});
        }
        else
        {
            while (d.size())
            {
                if (d.back().second > c[i])
                    d.pop_back();
                else
                    break;
            }
            d.push_back({i, c[i]});
        }
        if (d.front().first <= i - k)
            d.pop_front();
        ans += d.front().second * 2;
        n[d.front().first] += 2;
    }
    cout << ans << '\n';
    for (int i = 0; i < m; i++)
        cout << n[i] << ' ';
}

void input()
{
    cin >> m >> k;
    for (int i = 0; i < m; i++)
        cin >> c[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}