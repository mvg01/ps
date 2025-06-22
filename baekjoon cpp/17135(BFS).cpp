#include <bits/stdc++.h>
using namespace std;

int n, m, d, enemy, ans;
int f[16][16], mat[16][16];
int h[3][2] = {{0, -1}, {-1, 0}, {0, 1}}; // 왼쪽 적 우선 공격

vector<pair<int, int>> v, a;

void move()
{ // 적이 내려온다.
    for (int i = n - 2; i >= 0; i--)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 1 && mat[i + 1][j] == 0)
            {
                mat[i + 1][j] = 1;
                mat[i][j] = 0;
            }
        }
    }
}

void castle()
{
    for (int i = 0; i < 16; i++)
    {
        for (int j = 0; j < 16; j++)
            mat[i][j] = f[i][j];
    }
    int e = enemy; // 남은 적 수
    int cnt = 0;   // 이 배치에서 죽인 적 수
    while (e)
    {
        set<pair<int, int>> shoot; // 두 궁수가 같은 적을 쏠 순 있지만 한명의 적만 죽일 수 있다.
        for (auto i : a)
        {
            int vis[16][16] = {
                0,
            };
            queue<tuple<int, int, int>> q;      // 궁수 화살의 위치 (y,x)와 현재 이동거리
            q.push({i.first - 1, i.second, 1}); // 처음엔 무조건 위로(y-1,x) 좌표로 발사한다.
            vis[i.first - 1][i.second] = 1;
            while (q.size())
            {
                int y = get<0>(q.front());
                int x = get<1>(q.front());
                int c = get<2>(q.front());
                q.pop();
                if (mat[y][x] == 1)
                {
                    shoot.insert({y, x}); // 이번 턴에 죽을 적
                    break;
                }
                if (c == d) // 더이상 적에게 닿지 않는 화살이므로
                    continue;
                for (int i = 0; i < 3; i++)
                {
                    int yy = y + h[i][0];
                    int xx = x + h[i][1];
                    if (yy < 0 || xx >= m || xx < 0)
                        continue;
                    if (vis[yy][xx])
                        continue;
                    q.push({yy, xx, c + 1});
                }
            }
        }
        for (auto i : shoot)
        {
            mat[i.first][i.second] = 0;
            e--;   // 남은 적 감소
            cnt++; // 공격한 적 카운팅
        }
        for (int i = 0; i < m; i++)
        {
            if (mat[n - 1][i] == 1)
            { // 죽지 않고 성에 도달한 적 제거 (카운팅 X)
                e--;
                mat[n - 1][i] = 0;
            }
        }
        move();
    }
    ans = max(ans, cnt);
}

void bt(int cnt, int s)
{ // 백트래킹으로 모든 궁수 자리 검사
    if (cnt == 3)
    {
        castle();
        return;
    }
    for (int i = s; i < m; i++)
    {
        a.push_back({v[i].first, v[i].second});
        bt(cnt + 1, i + 1);
        a.pop_back();
    }
}

void solve()
{
    bt(0, 0);
    cout << ans;
}

void input()
{
    cin >> n >> m >> d;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> f[i][j];
            if (f[i][j] == 1)
                enemy++;
        }
    }
    for (int i = 0; i < m; i++)
        v.push_back({n, i});
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}