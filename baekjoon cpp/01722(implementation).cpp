#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll n, k, q, a[21], f[21];

void solve()
{
}

void input()
{
    cin >> n;
    f[1] = 1;
    for (int i = 2; i <= 20; i++)
        f[i] = f[i - 1] * i;
    cin >> k;
    if (k == 1)
    {
        cin >> q;
        int idx = n - 1;
        vector<int> v;
        for (int i = 1; i <= n; i++)
            v.push_back(i);
        for (int i = 0; i < n - 1; i++)
        {
            int cnt = 0;
            for (ll j = f[idx]; j <= f[idx + 1]; j += f[idx])
            {
                if (q <= j)
                {
                    cout << v[cnt] << ' ';
                    v.erase(v.begin() + cnt);
                    q -= j - f[idx];
                    break;
                }
                cnt++;
            }
            idx--;
        }
        cout << v[0];
    }
    else
    {
        bool vis[21] = {
            0,
        };
        ll ans = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            ll cnt = 0;
            for (int j = 1; j < a[i]; j++)
            {
                if (!vis[j])
                    cnt++;
            }
            ans += f[n - i - 1] * cnt;
            vis[a[i]] = 1;
        }
        cout << ans;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}