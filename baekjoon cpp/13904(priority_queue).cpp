#include <bits/stdc++.h>
using namespace std;

int n, ans;
vector<int> v[1001];
priority_queue<int, vector<int>, greater<int>> q;
void solve()
{
    for (int i = 1; i <= 1000; i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            if (q.size() < i)
                q.push(v[i][j]);
            else
            {
                if (q.top() < v[i][j])
                {
                    q.pop();
                    q.push(v[i][j]);
                }
            }
        }
    }
    while (q.size())
    {
        ans += q.top();
        q.pop();
    }
    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}