#include <bits/stdc++.h>
using namespace std;

int n, a[100001], mn = 2e9, b = 2e9;

void solve()
{
    int left = 0, right = n - 1;
    while (left != right)
    {
        int x = abs(a[left] + a[right]);
        if (mn > x)
        {
            mn = x;
            b = a[left] + a[right];
        }
        if (a[left] + a[right] >= 0)
            right--;
        else
            left++;
    }
    cout << b;
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