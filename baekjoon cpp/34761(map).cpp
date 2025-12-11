#include <bits/stdc++.h>
using namespace std;

int n, a[200001], b[400001];
map<int, bool> m;

void solve()
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] != b[i])
        {
            cout << "NO";
            return;
        }
    }
    for (int i = 0; i < 2 * n; i++)
    {
        if (m[b[i]] != 1)
        {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        m.insert({a[i], 1});
    }
    for (int i = 0; i < 2 * n; i++)
        cin >> b[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}