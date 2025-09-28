#include <bits/stdc++.h>
using namespace std;

int r, c, k;
char mat[51][51];
pair<int, int> item; // R회전, L회전
bool vis[51][51][151][151];
int d[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
map<char, int> m;

void solve()
{
    item.first = k;
    item.second = k;
    queue<tuple<int, int, pair<int, int>>> q;
    q.push({0, 0, item});
    vis[0][0][k][k];
    m.insert({'R', 0});
    m.insert({'D', 1});
    m.insert({'L', 2});
    m.insert({'U', 3});
    while (q.size())
    {
        int y = get<0>(q.front());
        int x = get<1>(q.front());
        auto t = get<2>(q.front());
        q.pop();
        if (y == r - 1 && x == c - 1)
        {
            cout << "Yes";
            return;
        }
        // 1. 원래의 이동
        char cur = mat[y][x];
        int dir = m[cur];
        int yy = y + d[dir][0];
        int xx = x + d[dir][1];
        if (yy < r && yy >= 0 && xx < c && xx >= 0 && !vis[yy][xx][t.first][t.second])
        {
            q.push({yy, xx, t});
            vis[yy][xx][t.first][t.second] = 1;
        }
        // 2. L 주문 (최대 3번이죠)
        auto left = t;
        for (int i = 0; i < 3; i++)
        {
            dir--;
            if (dir == -1)
                dir = 3;
            int yy = y + d[dir][0];
            int xx = x + d[dir][1];
            left.second--;
            if (left.second < 0)
                break;
            if (yy >= r || yy < 0 || xx >= c || xx < 0)
                continue;
            if (vis[yy][xx][left.first][left.second])
                continue;
            q.push({yy, xx, left});
            vis[yy][xx][left.first][left.second] = 1;
        }
        // 3. R 주문 (최대 3번이죠)
        auto right = t;
        dir = m[cur];
        for (int i = 0; i < 3; i++)
        {
            dir++;
            if (dir == 4)
                dir = 0;
            int yy = y + d[dir][0];
            int xx = x + d[dir][1];
            right.first--;
            if (right.first < 0)
                break;
            if (yy >= r || yy < 0 || xx >= c || xx < 0)
                continue;
            if (vis[yy][xx][right.first][right.second])
                continue;
            q.push({yy, xx, right});
            vis[yy][xx][right.first][right.second] = 1;
        }
    }
    cout << "No";
}

void input()
{
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++)
        cin >> mat[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}