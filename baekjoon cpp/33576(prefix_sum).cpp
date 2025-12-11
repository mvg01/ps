#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, m, q;
ll w[100005], sum[100005];

void solve()
{
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + w[i];
}

void input()
{
    cin >> n >> m >> q;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        w[a] = b;
    }
    solve();
    int left = 0, right = n + 1;
    for (int i = 0; i < q; i++)
    {
        int a;
        cin >> a;
        ll leftsum = max(ll(0), sum[a - 1] - sum[left]);
        ll rightsum = max(ll(0), sum[right - 1] - sum[a]);
        if (leftsum < rightsum)
        { // 왼쪽으로 가는게 좋음 (더 적게 부심)
            cout << leftsum << '\n';
            left = max(left, a);
        }
        else if (leftsum > rightsum)
        {
            cout << rightsum << '\n';
            right = min(right, a);
        }
        else
        {
            if (n - a >= a - 1)
            { // 이동거리가 최소
                cout << leftsum << '\n';
                left = max(left, a);
            }
            else
            {
                cout << rightsum << '\n';
                right = min(right, a);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}