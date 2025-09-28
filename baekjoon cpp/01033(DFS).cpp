#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, a, b, p, q, x = 1;
vector<tuple<ll, ll, ll>> v[10];
bool vis[10];
ll per[10];

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}

void dfs(int s)
{
    vis[s] = 1;
    for (auto i : v[s])
    {
        if (!vis[get<0>(i)])
        {
            per[get<0>(i)] = per[s] * get<2>(i) / get<1>(i);
            dfs(get<0>(i));
        }
    }
}

void solve()
{
    per[0] = x;
    dfs(0);
    ll g = per[0];
    for (int i = 1; i < n; i++)
        g = gcd(g, per[i]);
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            cout << per[i] / g << ' ';
        else
            cout << per[i] / g;
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> a >> b >> p >> q;
        v[a].push_back({b, p, q});
        v[b].push_back({a, q, p});
        x *= p * q / gcd(p, q);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}