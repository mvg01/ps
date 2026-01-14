#include <bits/stdc++.h>
using namespace std;

int n, a[1001], b[1001];

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        bool m[1001] = {0};
        vector<int> ans;
        m[i] = 1;
        int pre = i;
        bool chk = 0;
        ans.push_back(i);
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] - pre <= 0 || a[j] - pre > n)
            {
                chk = 1;
                break;
            }
            if (!m[a[j] - pre])
            {
                m[a[j] - pre] = 1;
                ans.push_back(a[j] - pre);
                pre = a[j] - pre;
            }
            else
            {
                chk = 1;
                break;
            }
        }
        if (!chk)
        {
            for (auto i : ans)
                cout << i << ' ';
            return;
        }
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n - 1; i++)
        cin >> a[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}