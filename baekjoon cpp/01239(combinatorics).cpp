#include <bits/stdc++.h>
using namespace std;

int n, a[9], ans;

void solve()
{
    sort(a, a + n);
    do
    {
        int cnt = 0, sum = 0;
        bool vis[101] = {
            0,
        };
        vis[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += a[i];
            vis[sum] = 1;
            if (sum > 50)
            {
                if (vis[sum - 50]) // 절반이 넘어간 상태에서 맞은 편 방문여부
                    cnt++;
            }
        }
        ans = max(ans, cnt);
    } while (next_permutation(a, a + n));
    cout << ans;
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