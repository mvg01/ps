#include <bits/stdc++.h>
using namespace std;

int n;
pair<int, int> a[100001];

bool com1(pair<int, int> x, pair<int, int> y)
{
    return x.second < y.second;
}

bool com2(pair<int, int> x, pair<int, int> y)
{
    return x.first > y.first;
}

void solve()
{
    sort(a, a + n, com1);
    int temp = a[0].second;
    sort(a, a + n, com2);
    if (a[0].first - temp < 0)
        cout << 0;
    else
        cout << a[0].first - temp;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i].first >> a[i].second;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}