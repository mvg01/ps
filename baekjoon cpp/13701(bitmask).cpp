#include <bits/stdc++.h>
using namespace std;

int a;
bitset<(1 << 25)> b;

void input()
{
    while (!cin.eof())
    {
        cin >> a;
        if (!b[a])
        {
            b[a] = 1;
            cout << a << ' ';
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}