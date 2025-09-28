#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<pair<int, int>> v;
bool com(pair<int, int> a, pair<int, int> b)
{
    if (a.first < b.first)
        return 1;
    else if (a.first > b.first)
        return 0;
    else
    {
        return a.second > b.second;
    }
}
void solve()
{
    long long ans = 0, cnt = 0;
    sort(v.begin(), v.end(), com);
    for (int i = 0; i < n; i++)
    {
        cnt += v[i].first;
        if (cnt <= m)
            ans += v[i].second;
    }
    cout << ans;
}
void input()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int t, g;
        cin >> t >> g;
        v.push_back({t, g});
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}