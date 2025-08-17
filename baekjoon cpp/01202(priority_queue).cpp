#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, k, c[300001];
vector<pair<int, int>> v;
priority_queue<int> pq;
ll ans;

void solve()
{
    sort(v.begin(), v.end());
    sort(c, c + k);
    int idx = 0;
    for (int i = 0; i < k; i++)
    {
        while (idx < n && v[idx].first <= c[i])
        {
            pq.push(v[idx].second);
            idx++;
        }
        if (pq.size())
        {
            ans += pq.top();
            pq.pop();
        }
    }
    cout << ans;
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }
    for (int i = 0; i < k; i++)
        cin >> c[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}