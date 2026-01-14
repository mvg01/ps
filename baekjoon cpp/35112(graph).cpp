#include <bits/stdc++.h>
using namespace std;

int n, m;
void solve()
{
    if (m <= n)
        cout << "Yes";
    else
        cout << "No";
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}