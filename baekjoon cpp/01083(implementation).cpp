#include <bits/stdc++.h>
using namespace std;

int n, a[51], s;
void solve()
{
    for (int i = 0; i < n - 1; i++)
    {
        int mx = a[i], idx = i;
        for (int j = i + 1; j < n; j++)
        {
            if (mx < a[j] && s - j + i >= 0)
            {
                mx = a[j];
                idx = j;
            }
        }
        if (mx == a[i])
            continue;
        if (s - idx + i >= 0)
        {
            while (s--)
            {
                swap(a[idx], a[idx - 1]);
                idx--;
                if (idx == i)
                    break;
            }
        }
        else
        {
            idx = i + 1;
            while (s)
            {
                if (a[idx] > a[idx - 1])
                {
                    swap(a[idx], a[idx - 1]);
                    s--;
                }
                idx++;
                if (idx == n - 1)
                    break;
            }
        }
        if (s == 0)
            break;
    }
    for (int i = 0; i < n; i++)
    {
        if (i != n - 1)
            cout << a[i] << ' ';
        else
            cout << a[i];
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    cin >> s;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}