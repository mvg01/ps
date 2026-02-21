#include <bits/stdc++.h>
using namespace std;

int n, a[140000], x;
void postOrder(int l, int r)
{
    if (l > r)
        return;
    int mid = (l + r) / 2;
    postOrder(l, mid - 1);
    postOrder(mid + 1, r);
    cout << a[mid] << ' ';
}

void solve()
{
    for (int i = 0; i < n; i++)
        if (a[i] == -1)
            a[i] = x;
    sort(a, a + n);
    postOrder(0, n - 1);
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> x;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}