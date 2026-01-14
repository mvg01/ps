#include <bits/stdc++.h>
using namespace std;

int n, t, k;
long long ans;
priority_queue<pair<int, int>> q;
void solve()
{
    cout << ans;
}

void input()
{
    cin >> n >> t >> k;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b;
        if (a == 1)
        {
            cin >> c;
            q.push({c, -b});
        }
        else
        {
            vector<int> temp;
            while (q.size())
            {
                int ff = q.top().first;
                int tt = -q.top().second;
                q.pop();
                if (b - tt <= t)
                    temp.push_back(ff);
                if (temp.size() == k)
                    break;
            }
            for (int i = 0; i < min(k, (int)temp.size()); i++)
                ans += temp[i];
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}