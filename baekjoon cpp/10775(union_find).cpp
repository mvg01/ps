#include <bits/stdc++.h>
using namespace std;

int g, p, ans;
int a[100001], par[100001];

void init()
{
    for (int i = 0; i < 100001; i++)
        par[i] = i;
}

int get_parent(int x)
{
    if (x == par[x])
        return x;
    else
        return par[x] = get_parent(par[x]);
}

void set_union(int a, int b)
{
    a = get_parent(a);
    b = get_parent(b);
    if (a < b)
        par[b] = a;
    else
        par[a] = b;
}

void solve()
{
    init();
    for (int i = 0; i < p; i++)
    {
        if (get_parent(a[i]) == 0)
            break;
        set_union(get_parent(a[i]), get_parent(a[i]) - 1);
        ans++;
    }
    cout << ans;
}

void input()
{
    cin >> g >> p;
    for (int i = 0; i < p; i++)
        cin >> a[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}