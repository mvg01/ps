#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> v[500001];
void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() > 2)
        {
            ans += v[i].size() - 2;
        }
    }
    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}