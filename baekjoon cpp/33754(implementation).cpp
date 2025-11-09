#include <bits/stdc++.h>
using namespace std;

int n, a[100001], b[100001];
void solve()
{
    int x = 1; // 1이면 위에만, 2이면 아래만, 3이면 모두
    if (b[0] == 1)
        x = 3;
    bool one = 0, two = 0;
    for (int i = 1; i < n; i++)
    {
        if (x == 1)
        {
            if (a[i] == 1)
                one = 1;
            else if (a[i] == 0)
            {
                cout << 0;
                return;
            }
        }
        else if (x == 2)
        {
            if (b[i] == 1)
                one = 1;
            else if (b[i] == 0)
            {
                cout << 0;
                return;
            }
        }
        else
        {
            if ((a[i] == 1 && b[i] == 0) || (a[i] == 0 && b[i] == 1))
                one = 1;
            else if (a[i] == 1 && b[i] == 1)
                two = 1;
            else
            {
                cout << 0;
                return;
            }
        }
        if (a[i] == 1 && b[i] == 1)
            x = 3;
        else if (a[i] == 1)
            x = 1;
        else if (b[i] == 1)
            x = 2;
        else
        {
            cout << 0;
            return;
        }
    }
    if (one)
        cout << 1;
    else if (two)
        cout << 2;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}