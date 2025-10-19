#include <bits/stdc++.h>
using namespace std;

// 차분배열기법 적용
int n, q;
int a[1000005], sum[1000005];

void solve()
{
    for (int i = 1; i < 1000001; i++)
        sum[i] = sum[i - 1] + a[i];
    for (int i = 0; i < q; i++)
    {
        int x;
        cin >> x;
        cout << sum[x] << '\n';
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int s, e;
        cin >> s >> e;
        a[s]++;
        a[e + 1]--;
    }
    cin >> q;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}