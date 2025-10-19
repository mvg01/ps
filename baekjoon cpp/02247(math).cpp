#include <bits/stdc++.h>
using namespace std;

int n, ans;
void solve()
{
    // i로 나눠지는 모든 수의 개수 * i를 n/2 까지 더한다.
    for (int i = 2; i <= n / 2; i++)
    {
        ans += i * (n / i - 1);
        ans %= 1000000;
    }
    cout << ans;
}

void input()
{
    cin >> n;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}