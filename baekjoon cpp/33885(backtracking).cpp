#include <bits/stdc++.h>
using namespace std;

int n, m, a[11];
map<string, int> id;
vector<pair<int, int>> v[11];
bool t[5][25], vis[11];

void f(int cur)
{
    if (cur >= m)
    {
        cout << "YES";
        exit(0);
    }
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            bool no = 0;
            for (int j = 0; j < v[i].size(); j++)
            {
                if (t[v[i][j].first][v[i][j].second])
                {
                    no = 1;
                    break;
                }
            }
            if (!no)
            {
                vis[i] = 1;
                for (int j = 0; j < v[i].size(); j++)
                {
                    t[v[i][j].first][v[i][j].second] = 1;
                }
                f(cur + a[i]);
                vis[i] = 0;
                for (int j = 0; j < v[i].size(); j++)
                {
                    t[v[i][j].first][v[i][j].second] = 0;
                }
            }
        }
    }
}

void solve()
{
    f(0);
    cout << "NO";
}

void input()
{
    cin >> n >> m;
    id["MON"] = 0;
    id["TUE"] = 1;
    id["WED"] = 2;
    id["THU"] = 3;
    id["FRI"] = 4;
    for (int i = 0; i < n; i++)
    {
        int c, s, h;
        string d;
        cin >> c >> s;
        a[i] = c;
        for (int j = 0; j < s; j++)
        {
            cin >> d >> h;
            v[i].push_back({id[d], h});
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