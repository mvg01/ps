#include <bits/stdc++.h>
using namespace std;

int t, n, m;
int a[1000001], b[1000001];

void solve()
{
    long long ans = 0;
    sort(b, b + m);
    for (int i = 0; i < n; i++)
    {
        int left = 0, right = m - 1, mid, dif = 2e9 + 1, plus = 1e9;
        while (left <= right)
        {
            mid = (left + right) / 2;
            int temp = a[i] - b[mid];
            if (temp > 0)
            {
                left = mid + 1;
            }
            else
            {
                right = mid - 1;
            }
            if (dif >= abs(a[i] - b[mid]))
            {
                if (dif == abs(a[i] - b[mid]))
                    plus = min(plus, b[mid]);
                else
                {
                    dif = abs(a[i] - b[mid]);
                    plus = b[mid];
                }
            }
        }
        ans += plus;
    }
    cout << ans << '\n';
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> m;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < m; i++)
            cin >> b[i];
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}