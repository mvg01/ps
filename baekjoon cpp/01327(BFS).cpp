#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> a;
map<vector<int>, bool> m;

void solve()
{
    queue<pair<vector<int>, int>> q;
    q.push({a, 0});
    m[a] = 1;
    while (q.size())
    {
        vector<int> v = q.front().first;
        int t = q.front().second;
        q.pop();
        bool chk = 0;
        for (int i = 1; i <= n; i++)
            if (v[i - 1] != i)
                chk = 1;
        if (!chk)
        {
            cout << t;
            return;
        }
        for (int i = 0; i < n - k + 1; i++)
        {
            vector<int> r, o;
            for (int j = 0; j < i; j++)
                o.push_back(v[j]);
            for (int j = i; j < k + i; j++)
                r.push_back(v[j]);
            reverse(r.begin(), r.end());
            o.insert(o.end(), r.begin(), r.end());
            for (int j = k + i; j < n; j++)
                o.push_back(v[j]);
            if (m[o])
                continue;
            q.push({o, t + 1});
            m[o] = 1;
        }
    }
    cout << -1;
}

void input()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        a.push_back(p);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}