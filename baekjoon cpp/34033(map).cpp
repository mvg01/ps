#include <bits/stdc++.h>
using namespace std;

int n, m, ans;
map<string, int> p;
void solve()
{
}

void input()
{
    cin >> n >> m;
    string s;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> x;
        p.insert({s, x});
    }
    for (int i = 0; i < m; i++)
    {
        cin >> s >> x;
        if (p[s] * 105 < x * 100)
            ans++;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}