#include <bits/stdc++.h>
using namespace std;

int n, ans[1000001];
vector<int> v;

void solve()
{
    for (int i = 2; i <= 1000000; i++)
        v.push_back(i);
    for (int i = 0; i < v.size(); i++)
    {
        long long sum = 0;
        for (int j = i; j < v.size(); j++)
        {
            sum += v[j];
            if (sum > 1000000)
                break;
            ans[sum]++;
        }
    }
}

void input()
{
    solve();
    while (1)
    {
        cin >> n;
        if (n == 0)
            break;
        cout << ans[n] << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}