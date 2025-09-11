#include <bits/stdc++.h>
using namespace std;

int n, m, cnt = 2;
const int MX = 10000 * 500 + 1;
bool chk[MX];
int nxt[MX][26];

void insert(string s)
{
    int cur = 1;
    for (auto i : s)
    {
        if (nxt[cur][i - 'a'] == -1)
        {
            nxt[cur][i - 'a'] = cnt++;
        }
        cur = nxt[cur][i - 'a'];
    }
    chk[cur] = 1;
}

bool find(string s)
{
    int cur = 1;
    for (auto i : s)
    {
        if (nxt[cur][i - 'a'] == -1)
            return 0;
        cur = nxt[cur][i - 'a'];
    }
    return 1;
}

void solve()
{
}

void input()
{
    cin >> n >> m;
    for (int i = 0; i < MX; i++)
    {
        for (int j = 0; j < 26; j++)
            nxt[i][j] = -1;
    }
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        insert(s);
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        string s;
        cin >> s;
        if (find(s))
            ans++;
    }
    cout << ans;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}