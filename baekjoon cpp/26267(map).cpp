#include <bits/stdc++.h>
using namespace std;

int n;
map<int, long long> m;

void solve()
{
    long long ans = 0;
    for (auto i : m)
        ans = max(ans, i.second);
    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        m[a - b] += c;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}