#include <bits/stdc++.h>
using namespace std;

int n, m;
int y[100001], x[100001];
void solve()
{
    sort(y, y + m);
    sort(x, x + m);
    int ans = 0;
    int my = y[m / 2], mx = x[m / 2]; // 좌표 가운데 값
    // cout << my << ' ' << mx << ' ';
    for (int i = 0; i < m; i++)
    {
        ans += abs(my - y[i]);
        ans += abs(mx - x[i]);
    }
    cout << ans;
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> y[i] >> x[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}