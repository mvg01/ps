#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> v[101], a, b;
bool vis[101];
void solve()
{
    queue<pair<int, bool>> q; // 사람, 팀
    int cnt = 0;
    while (cnt != n)
    {
        for (int i = 1; i <= n; i++)
        {
            if (!vis[i])
            {
                q.push({i, 0});
                vis[i] = 1;
                a.push_back(i);
                cnt++;
                break;
            }
        }
        while (q.size())
        {
            int p = q.front().first;
            bool t = q.front().second;
            q.pop();
            for (auto j : v[p])
            {
                if (!vis[j])
                {
                    vis[j] = 1;
                    if (t)
                        a.push_back(j);
                    else
                        b.push_back(j);
                    q.push({j, !t});
                    cnt++;
                }
            }
        }
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    cout << a.size() << '\n';
    for (auto i : a)
        cout << i << ' ';
    cout << '\n'
         << b.size() << '\n';
    for (auto i : b)
        cout << i << ' ';
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int t, x;
        cin >> t;
        for (int j = 0; j < t; j++)
        {
            cin >> x;
            v[i + 1].push_back(x);
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