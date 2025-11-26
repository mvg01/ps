#include <bits/stdc++.h>
using namespace std;

int t, n;

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout << i + 1 << ' ' << n / 2 + 1 << '\n';
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}