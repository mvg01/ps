#include <bits/stdc++.h>
using namespace std;

int n, m;
long long a[61];
void solve()
{
    long long ans1 = 1, ans2 = 1;
    sort(a, a + n);
    int idx = 0;
    bool chk = 0, chk2 = 0;
    for (; idx < n; idx++)
    {
        if (a[idx] < 0)
            ans1 *= a[idx];
        else
            break;
    }
    if (ans1 < 0)
        ans1 /= a[idx - 1];
    if (idx == 1 || idx == 0) // 음수 없거나 1개인 경우 무조건 제외
        chk = 1;
    for (; idx < n; idx++)
    {
        if (a[idx] == 0)
            continue;
        ans2 *= a[idx];
        chk2 = 1; // 양수가 하나라도 포함
    }
    if (chk && chk2 == 0)
        cout << 0 << '\n';
    else if (chk)
        cout << ans2 << '\n';
    else
        cout << ans1 * ans2 << '\n';
}

void input()
{
    cin >> n >> m;
    while (m--)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        if (n == 1)
        {
            cout << a[0] << '\n';
            continue;
        }
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}