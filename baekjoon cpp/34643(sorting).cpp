#include <bits/stdc++.h>
using namespace std;

int n;
long long a[11], b[11], sum;

void solve()
{
    sort(b, b + n, greater<long long>());
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        sum += b[i];
        double avg = (double)(sum + a[i]) / (i + 1);
        ans = max(ans, avg);
    }
    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout << fixed;
    cout << setprecision(1);
    input();
    solve();
}