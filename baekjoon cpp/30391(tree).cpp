#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> v[300001];

void solve()
{
    int cnt = 0, next = 2;
    queue<int> q;
    q.push(1);
    while (q.size())
    {
        int x = q.front();
        q.pop();
        int i = v[x].size();
        for (; i < k; i++)
        {
            v[x].push_back(next);
            v[next].push_back(x);
            q.push(next);
            cnt++;
            cout << x << ' ' << next++ << '\n';
            if (cnt == n - 1)
                return;
        }
    }
}

void input()
{
    cin >> n >> k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}