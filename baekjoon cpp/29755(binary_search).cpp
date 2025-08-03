#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, m, b[200001], ans = 1e15;
vector<pair<ll, ll>> v;

void solve()
{
    sort(b, b + n);
    sort(v.begin(), v.end());
    ll s = 0, e = 200000000, mid;
    while (s <= e)
    {
        mid = (s + e) / 2;
        int idx = 0;
        bool no = 0;
        for (int i = 0; i < m; i++)
        {
            if (idx == n)
            {
                no = 1;
                break;
            }
            if (v[i].second * abs(v[i].first - b[idx]) > mid)
            {
                idx++;
                i--;
            }
        }
        if (no)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
            ans = min(ans, mid);
        }
    }
    cout << ans;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < m; i++)
    {
        int a, w;
        cin >> a >> w;
        v.push_back({a, w});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}