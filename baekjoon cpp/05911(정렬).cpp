#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, b, ans = 0;
vector<pair<ll, pair<ll, ll>>> t;
void solve()
{
    sort(t.begin(), t.end(), greater<>());
    for (int i = 0; i < n; i++)
    {
        ll cnt = 0, tmp = b;
        tmp -= t[i].second.first / 2 + t[i].second.second;
        if (tmp >= 0)
        {
            cnt++;
            for (int j = n - 1; j >= 0; j--)
            {
                if (i == j)
                    continue;
                tmp -= t[j].second.first + t[j].second.second;
                if (tmp < 0)
                    break;
                cnt++;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
}

void input()
{
    cin >> n >> b;
    for (int i = 0; i < n; i++)
    {
        ll p, s;
        cin >> p >> s;
        t.push_back({p / 2 + s, {p, s}});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}