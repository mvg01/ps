#include <bits/stdc++.h>
using namespace std;

int t, q;
vector<pair<int, string>> v;
string s, p[3] = {"qwertyuiop", "asdfghjkl", "zxcvbnm"};
int d[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
map<char, int> m[26];

void dis(int y, int x)
{
    int vis[3][11];
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 11; j++)
            vis[i][j] = 0;
    }
    queue<pair<int, int>> q;
    q.push({y, x});
    vis[y][x] = 1;
    m[p[y][x] - 'a'].insert({p[y][x] - 'a', 0});
    while (q.size())
    {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int dy = yy + d[i][0];
            int dx = xx + d[i][1];
            if (dy >= 3 || dy < 0)
                continue;
            int len = p[dy].length();
            if (dx >= len || dx < 0)
                continue;
            if (!vis[dy][dx])
            {
                m[p[y][x] - 'a'].insert({p[dy][dx] - 'a', vis[yy][xx]});
                q.push({dy, dx});
                vis[dy][dx] = vis[yy][xx] + 1;
            }
        }
    }
}

void solve()
{
    sort(v.begin(), v.end());
    for (auto i : v)
    {
        cout << i.second << ' ' << i.first << '\n';
    }
}

void input()
{
    cin >> t;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < p[i].length(); j++)
            dis(i, j);
    }
    while (t--)
    {
        cin >> s >> q;
        int len = s.length();
        for (int i = 0; i < q; i++)
        {
            string u;
            cin >> u;
            int sum = 0;
            for (int j = 0; j < len; j++)
            {
                sum += m[s[j] - 'a'][u[j] - 'a'];
            }
            v.push_back({sum, u});
        }
        solve();
        v.clear();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}