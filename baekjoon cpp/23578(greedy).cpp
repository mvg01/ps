#include <bits/stdc++.h>
using namespace std;

int n, ans, a[2000001];
void solve()
{
    sort(a, a + n);
    int cnt = 0;
    int idx = (n % 2) ? n / 2 + 1 : n / 2;
    for (int i = 0; i < idx; i++)
    {
        while (a[i])
        {
            cnt++;
            a[i] /= 2;
        }
    }
    cout << cnt - (idx - 1);
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