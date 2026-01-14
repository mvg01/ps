#include <bits/stdc++.h>
using namespace std;

int a, b, c;
void solve()
{
    int a1 = 0, a2 = 0;
    a1 += a / 3;
    a2 += b / 4;
    int left3 = a % 3;
    int left4 = b % 4;
    for (int i = 0; i <= c; i++)
    {
        if ((left3 + i) % 3 == 0 && (left4 + c - i) % 4 == 0)
        {
            cout << a1 + (left3 + i) / 3 << ' ' << a2 + (left4 + c - i) / 4;
            return;
        }
    }
    cout << -1;
}

void input()
{
    cin >> a >> b >> c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}