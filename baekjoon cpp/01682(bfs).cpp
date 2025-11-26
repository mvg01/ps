#include <bits/stdc++.h>
using namespace std;

int a[8];
map<vector<int>, bool> m;

void solve()
{
    vector<int> x = {1, 2, 3, 4, 5, 6, 7, 8};
    queue<pair<vector<int>, int>> q;
    q.push({x, 0});
    m.insert({x, 1});
    while (q.size())
    {
        vector<int> v = q.front().first;
        int cnt = q.front().second;
        q.pop();
        bool chk = 0;
        for (int i = 0; i < 8; i++)
        {
            if (a[i] != v[i])
                chk = 1;
        }
        if (!chk)
        {
            cout << cnt;
            return;
        }
        vector<int> t = v;
        for (int i = 0; i < 4; i++)
        {
            swap(t[i], t[8 - i - 1]);
        }
        if (!m[t])
        {
            m[t] = 1;
            q.push({t, cnt + 1});
        }

        t = v;
        t[0] = t[3];
        for (int i = 1; i < 4; i++)
            t[i] = v[i - 1];
        t[7] = t[4];
        for (int i = 6; i > 3; i--)
            t[i] = v[i + 1];
        if (!m[t])
        {
            m[t] = 1;
            q.push({t, cnt + 1});
        }

        t = v;
        t[1] = v[2];
        t[6] = v[1];
        t[5] = v[6];
        t[2] = v[5];
        if (!m[t])
        {
            m[t] = 1;
            q.push({t, cnt + 1});
        }

        t = v;
        swap(t[0], t[4]);
        if (!m[t])
        {
            m[t] = 1;
            q.push({t, cnt + 1});
        }
    }
}

void input()
{
    for (int i = 0; i < 8; i++)
        cin >> a[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}