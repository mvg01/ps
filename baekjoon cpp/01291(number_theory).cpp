#include <bits/stdc++.h>
using namespace std;

int n, a[2701];

void f()
{
    for (int i = 0; i <= n; i++)
        a[i] = i;
    for (int i = 2; i <= n; i++)
    {
        if (a[i] < i)
            continue;
        for (int j = i + i; j <= n; j += i)
        {
            if (a[j] == j)
                a[j] = i;
        }
    }
}

void solve()
{
    bool im = 0, ih = 0;
    if (n != 5 && n >= 4)
    {
        string s = to_string(n);
        int sum = 0;
        for (char c : s)
            sum += c - '0';
        if (sum % 2 == 1)
            im = 1;
    }
    f();
    if (n == 4 || n == 2)
        ih = 1;
    int k = n;
    set<int> s; // 소인수의 종류 확인용
    while (k > 1)
    {
        s.insert(a[k]);
        k /= a[k];
    }
    if (s.size() % 2 == 0 && a[n] != n) // 종류 짝수면서 합성수
        ih = 1;
    if (im && !ih)
        cout << 1;
    else if (!im && ih)
        cout << 2;
    else if (!im && !ih)
        cout << 3;
    else if (im && ih)
        cout << 4;
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