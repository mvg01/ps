#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> a;

void shuffle()
{
    vector<int> b, c;
    for (int i = 0; i < n; i++)
        b.push_back(a[i]);
    for (int i = n; i < a.size(); i++)
        c.push_back(a[i]);
    a.clear();
    for (int i = 0; i < n; i++)
    {
        a.push_back(b[i]);
        a.push_back(c[i]);
    }
}

void change(int x)
{
    vector<int> b, c;
    for (int i = 0; i < x; i++)
        b.push_back(a[i]);
    for (int i = x; i < a.size(); i++)
        c.push_back(a[i]);
    a.clear();
    for (int i : c)
        a.push_back(i);
    for (int i : b)
        a.push_back(i);
}

void solve()
{
    for (int i = 0; i < a.size(); i++)
        cout << a[i] << '\n';
}

void input()
{
    cin >> n >> m;
    for (int i = 1; i <= n * 2; i++)
        a.push_back(i);
    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        if (x == 0)
        {
            shuffle();
        }
        else
        {
            change(x);
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}