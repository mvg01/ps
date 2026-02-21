#include <bits/stdc++.h>
using namespace std;

int n, mx;
vector<vector<int>> t;
void solve()
{
    for (int ans = 1; ans <= mx; ans++)
    {
        map<vector<int>, bool> m;
        bool chk = 0;
        for (int i = 0; i < n; i++)
        {
            vector<int> temp;
            for (int j = 0; j < min((int)t[i].size(), ans); j++)
            {
                temp.push_back(t[i][j]);
            }
            if (m.find(temp) == m.end())
                m.insert({temp, 1});
            else
            {
                chk = 1;
                break;
            }
        }
        if (!chk)
        {
            cout << ans;
            break;
        }
    }
}

void input()
{
    cin >> n;
    int p = n;
    while (p--)
    {
        vector<int> v;
        while (1)
        {
            int x;
            cin >> x;
            if (x == -1)
                break;
            v.push_back(x);
        }
        mx = max(mx, (int)v.size());
        t.push_back(v);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}