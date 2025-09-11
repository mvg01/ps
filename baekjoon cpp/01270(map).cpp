#include <bits/stdc++.h>
using namespace std;

int t, n;
map<long long, int> m;

void solve()
{
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            long long x;
            cin >> x;
            m[x]++;
        }
        bool brk = 0;
        for (auto i : m)
        {
            if (i.second > n / 2)
            {
                cout << i.first << '\n';
                brk = 1;
                break;
            }
        }
        if (!brk)
            cout << "SYJKGW\n";
        m.clear();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}