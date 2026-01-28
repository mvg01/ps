#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, d[100001], mx;
ll sum;

void solve()
{
    if (sum == 1 && mx == 1)
    {
        cout << "Happy";
        return;
    }
    sum -= mx;
    if (sum >= mx)
        cout << "Happy";
    else
        cout << "Unhappy";
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> d[i];
        mx = max(mx, d[i]);
        sum += d[i];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}