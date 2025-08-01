#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k;
vector<int> v;
ll cnt[21], ans;

void solve()
{
    for (int i = 0; i <= k; i++)
    {
        cnt[v[i]]++;
        if (cnt[v[i]] > 1)
            ans += cnt[v[i]] - 1;
    }
    int idx = 0;
    for (int i = k + 1; i < n; i++)
    {
        cnt[v[idx++]]--;
        cnt[v[i]]++;
        if (cnt[v[i]] > 1)
            ans += cnt[v[i]] - 1;
    }
    cout << ans;
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s.length());
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}