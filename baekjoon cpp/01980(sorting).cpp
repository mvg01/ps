#include <bits/stdc++.h>
using namespace std;

int n, m, t;
vector<pair<int, int>> ans;

bool com(pair<int, int> a, pair<int, int> b)
{
    if (a.first != b.first)
        return a.first < b.first;
    return a.second > b.second;
}

void solve()
{
    if (n > m)
        swap(n, m);
    for (int i = t / n; i >= 0; i--)
    {
        int cola, sum = i;
        int temp = t - n * i;
        sum += temp / m;
        cola = temp % m;
        ans.push_back({cola, sum});
    }
    sort(ans.begin(), ans.end(), com);
    cout << ans[0].second << ' ' << ans[0].first;
}

void input()
{
    cin >> n >> m >> t;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}