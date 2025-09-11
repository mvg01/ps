#include <bits/stdc++.h>
using namespace std;

int t, n;
string p;

void solve()
{
    int len = p.length(), sum = 0;
    for (int i = 0; i < len; i++)
        sum += p[i] - '0';
    int start = n - 1, cnt = 0;
    if (start == 0)
    {
        cout << "4 2\n";
        return;
    }
    for (;;)
    {
        int temp;
        string s = p;
        for (int j = 0; j < 10; j++)
        {
            if (p[start] - '0' == j)
                continue;
            temp = sum - (p[start] - '0') + j;
            if (temp % 3 == 0)
            {
                s[start] = j + '0';
                cout << s << ' ' << 3 << '\n';
                cnt++;
            }
            if (cnt == n)
                break;
        }
        if (cnt == n)
            break;
        start--;
    }
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> n >> p;
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}