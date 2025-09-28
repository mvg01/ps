#include <bits/stdc++.h>
using namespace std;

int ans = 1e9;
char mat[6][6];
bool vis[6][6];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int, int>> v;

bool check()
{
    bool bfs[6][6];
    int y, x;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (mat[i][j] == '*')
            {
                y = i;
                x = j;
            }
            bfs[i][j] = 0;
        }
    }
    queue<pair<int, int>> q;
    int count = 1;
    q.push({y, x});
    bfs[y][x] = 1;
    while (q.size())
    {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        if (count == v.size())
            return 1;
        for (int i = 0; i < 4; i++)
        {
            int dy = yy + d[i][0];
            int dx = xx + d[i][1];
            if (dy >= 5 || dy < 0 || dx >= 5 || dx < 0)
                continue;
            if (bfs[dy][dx])
                continue;
            if (mat[dy][dx] == '*')
            {
                q.push({dy, dx});
                bfs[dy][dx] = 1;
                count++;
            }
        }
    }
    return 0;
}

void dfs(int idx, int cnt)
{
    if (idx == v.size())
    {
        if (check())
            ans = min(ans, cnt);
        return;
    }
    if (cnt >= ans)
        return;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (!vis[i][j])
            {
                vis[i][j] = 1;
                mat[i][j] = '*';
                int dis = abs(v[idx].first - i) + abs(v[idx].second - j);
                dfs(idx + 1, cnt + dis);
                mat[i][j] = '.';
                vis[i][j] = 0;
            }
        }
    }
}

void solve()
{
    dfs(0, 0);
    cout << ans;
}

void input()
{
    for (int i = 0; i < 5; i++)
    {
        cin >> mat[i];
        for (int j = 0; j < 5; j++)
        {
            if (mat[i][j] == '*')
            {
                v.push_back({i, j});
                mat[i][j] = '.';
            }
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

// 비트마스크 활용 풀이
#include <bits/stdc++.h>
using namespace std;

int ans = 1e9;
char mat[6][6];
bool vis[6][6];
int d[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
vector<pair<int, int>> v;
unordered_map<uint32_t, int> st;

bool check()
{
    bool bfs[6][6];
    int y, x;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (mat[i][j] == '*')
            {
                y = i;
                x = j;
            }
            bfs[i][j] = 0;
        }
    }
    queue<pair<int, int>> q;
    int count = 1;
    q.push({y, x});
    bfs[y][x] = 1;
    while (q.size())
    {
        int yy = q.front().first;
        int xx = q.front().second;
        q.pop();
        if (count == v.size())
            return 1;
        for (int i = 0; i < 4; i++)
        {
            int dy = yy + d[i][0];
            int dx = xx + d[i][1];
            if (dy >= 5 || dy < 0 || dx >= 5 || dx < 0)
                continue;
            if (bfs[dy][dx])
                continue;
            if (mat[dy][dx] == '*')
            {
                q.push({dy, dx});
                bfs[dy][dx] = 1;
                count++;
            }
        }
    }
    return 0;
}

uint32_t getState()
{
    uint32_t state = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (mat[i][j] == '*')
            {
                int idx = i * 5 + j;
                state |= (1u << idx);
            }
        }
    }
    return state;
}

void dfs(int idx, int cnt)
{
    if (idx == v.size())
    {
        uint32_t state = getState();
        if (st.count(state) && st[state] <= cnt)
            return;
        st[state] = cnt;
        if (check())
            ans = min(ans, cnt);
        return;
    }
    if (cnt >= ans)
        return;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if (!vis[i][j])
            {
                vis[i][j] = 1;
                mat[i][j] = '*';
                int dis = abs(v[idx].first - i) + abs(v[idx].second - j);
                dfs(idx + 1, cnt + dis);
                mat[i][j] = '.';
                vis[i][j] = 0;
            }
        }
    }
}

void solve()
{
    dfs(0, 0);
    cout << ans;
}

void input()
{
    for (int i = 0; i < 5; i++)
    {
        cin >> mat[i];
        for (int j = 0; j < 5; j++)
        {
            if (mat[i][j] == '*')
            {
                v.push_back({i, j});
                mat[i][j] = '.';
            }
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