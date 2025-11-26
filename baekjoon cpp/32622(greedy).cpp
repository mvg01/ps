#include <bits/stdc++.h>
using namespace std;

int n, a[300001], ans = 1;
vector<int> p;

void solve()
{
    int temp = 1;
    p.push_back(1);
    for (int i = 1; i < n; i++)
    {
        if (a[i] != a[i - 1])
        {
            temp = 1;
            p.push_back(1);
        }
        else
        {
            temp++;
            p.back()++;
        }
        ans = max(ans, temp);
    }
    for (int i = 1; i < p.size(); i++)
    {
        ans = max(ans, p[i - 1] + p[i]);
    }
    cout << ans;
}
void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}