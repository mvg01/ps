#include <bits/stdc++.h>
using namespace std;

int n, s, a[20001];
void solve()
{
    sort(a, a + n);
    int l = 0, r = n - 1, cnt = 0;
    while (l < r)
    {
        if (a[l] + a[r] <= s)
        {
            cnt += r - l;
            l++;
        }
        else
            r--;
    }
    cout << cnt;
}

void input()
{
    cin >> n >> s;
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