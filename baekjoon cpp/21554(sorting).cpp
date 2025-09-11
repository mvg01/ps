#include <bits/stdc++.h>
using namespace std;

int n, a[101];
vector<pair<int, int>> v;
void solve()
{
    for (int i = 0; i < n - 1; i++)
    {
        int mn = a[i], idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (mn > a[j])
            {
                mn = a[j];
                idx = j;
            }
        }
        if (idx != i)
        {
            v.push_back({i + 1, idx + 1});
            reverse(a + i, a + idx + 1);
        }
    }
    if (v.size() <= 100)
    {
        cout << v.size() << '\n';
        for (auto i : v)
            cout << i.first << ' ' << i.second << '\n';
    }
    else
        cout << -1;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}