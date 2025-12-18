#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
vector<tuple<ll, ll, int>> v;
bool com(tuple<ll, ll, int> a, tuple<ll, ll, int> b)
{
    if (get<0>(a) * get<1>(b) < get<0>(b) * get<1>(a))
        return 1;
    else if (get<0>(a) * get<1>(b) > get<0>(b) * get<1>(a))
        return 0;
    else
    {
        if (get<1>(a) > get<1>(b))
            return 0;
        else if (get<1>(a) < get<1>(b))
            return 1;
        else
        {
            return get<2>(a) < get<2>(b);
        }
    }
}

void solve()
{
    sort(v.begin(), v.end(), com);
    for (int i = 0; i < k; i++)
    {
        cout << get<2>(v[i]) << '\n';
    }
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a;
        ll b, c;
        cin >> a >> b >> c;
        v.push_back({b, c, a});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}