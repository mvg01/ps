#include <bits/stdc++.h>
using namespace std;

int n, k;
int d[10001], s[10001];

void solve()
{
    int temp[10001] = {
        0,
    };
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < n; j++)
            temp[d[j] - 1] = s[j];
        for (int j = 0; j < n; j++)
            s[j] = temp[j];
    }
    for (int i = 0; i < n; i++)
        cout << s[i] << ' ';
}
void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> s[i];
    for (int i = 0; i < n; i++)
        cin >> d[i];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}