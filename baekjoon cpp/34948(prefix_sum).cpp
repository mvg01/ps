#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> x[200001];
long long sum[200001], ans;
void solve()
{
    sort(x, x + n, greater<pair<int, int>>());
    int pre = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == 0)
        {
            ans = (long long)x[i].first * x[i].second;
            sum[0] = x[i].second;
            pre = x[i].first;
            continue;
        }
        sum[i] = sum[i - 1] + x[i].second;
        if (pre == x[i].first)
            ans = max(ans, sum[i] * pre);
        else
            ans = max(ans, sum[i] * x[i].first);

        pre = x[i].first;
    }
    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x[i].first;
    for (int i = 0; i < n; i++)
        cin >> x[i].second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}