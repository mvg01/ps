#include <bits/stdc++.h>
using namespace std;

int p, n, a[100001];
long long sum, ans;

void solve()
{
    sort(a, a + n);
    int idx = 0;
    for (int i = 0; i < n; i++)
    {
        sum += a[i];
        if (sum >= p)
        {
            sum -= p;
            idx = i;
            break;
        }
    }
    if (idx == 0)
        idx = n;
    cout << idx << ' ';
    p--;
    for (int i = 0; i < idx; i++)
    {
        ans += p;
        p -= a[i];
    }
    cout << ans;
}

void input()
{
    cin >> p >> n;
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