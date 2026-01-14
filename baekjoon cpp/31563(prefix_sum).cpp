#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, q;
ll g[200001], sum[200001];

void solve(int a, int b, int turn)
{
    int c;
    cin >> c;
    int left = b + turn;
    if (left <= 0)
        left += n;
    if (left > n)
        left -= n;
    int right = c + turn;
    if (right <= 0)
        right += n;
    if (right > n)
        right -= n;

    if (left > right)
        cout << sum[n] - sum[left - 1] + sum[right];
    else
        cout << sum[right] - sum[left - 1];
    cout << '\n';
}

void input()
{
    cin >> n >> q;
    for (int i = 1; i <= n; i++)
        cin >> g[i];
    sum[0] = 0;
    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + g[i];
    int turn = 0;
    for (int i = 0; i < q; i++)
    {
        int a, b, c;
        cin >> a >> b;
        if (a == 1)
            turn -= b;
        else if (a == 2)
            turn += b;
        else
            solve(a, b, turn);
        if (abs(turn) > n)
        {
            if (turn > 0)
                turn -= n;
            else
                turn += n;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}