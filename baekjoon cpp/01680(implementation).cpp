#include <bits/stdc++.h>
using namespace std;

int t, w, n;
pair<int, int> v[1001];

void solve()
{
    int ans = 0, temp = 0, pre = 0;
    for (int i = 0; i < n; i++)
    {
        if (temp + v[i].second > w) // 용량이 넘쳐서 돌아갔다가 와야함
        {
            ans += v[i].first - pre;
            ans += v[i].first;
            temp = 0;
            i--;
            pre = 0;
        }
        else
        {
            temp += v[i].second;
            ans += v[i].first - pre;
            pre = v[i].first;
            if (temp == w) // 용량이 딱 맞게 꽉 차서 돌아갔다가 와야함
            {
                ans += v[i].first;
                temp = 0;
                pre = 0;
            }
        }
    }
    cout << ans + pre << '\n';
}

void input()
{
    cin >> t;
    while (t--)
    {
        cin >> w >> n;
        for (int i = 0; i < n; i++)
        {
            int a, b;
            cin >> a >> b;
            v[i] = {a, b};
        }
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}