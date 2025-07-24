#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m;
ll cnt[200001], ans;
vector<ll> v;

void solve()
{
    for (int i = 1; i <= n; i++)
        v.push_back(cnt[i]);
    sort(v.begin(), v.end());
    ll f = v[0];
    for (int i = 1; i < n; i++)
    {
        if (f >= v[i])
        {
            ans += f - v[i] + 1;
            v[i] += f - v[i] + 1;
            f = v[i];
        }
        f = v[i];
    }
    cout << ans;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cnt[a]++;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}