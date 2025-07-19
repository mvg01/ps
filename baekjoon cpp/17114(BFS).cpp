#include <bits/stdc++.h>
using namespace std;

int m, n, o, p, q, r, s, t, u, v, w, sum, ans;
typedef struct tomato
{
    int cnt = 0;
    int m, n, o, p, q, r, s, t, u, v, w;
} Tomato;

int d[22][11] = {
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {-1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, -1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, -1, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, -1, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, -1, 0, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, -1, 0, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, -1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, -1, 0, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, -1, 0, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, -1, 0},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, -1}};

// 좌표 평탄화 (11차원 좌표를 1차원으로)
long long get_index(int c1, int c2, int c3, int c4, int c5, int c6, int c7, int c8, int c9, int c10, int c11)
{
    long long idx = c11;
    idx = idx * v + c10;
    idx = idx * u + c9;
    idx = idx * t + c8;
    idx = idx * s + c7;
    idx = idx * r + c6;
    idx = idx * q + c5;
    idx = idx * p + c4;
    idx = idx * o + c3;
    idx = idx * n + c2;
    idx = idx * m + c1;
    return idx;
}

queue<Tomato> qe;
bool vis[1000001];

void solve()
{
    while (qe.size())
    {
        Tomato cur = qe.front();
        qe.pop();
        ans = max(ans, cur.cnt);
        for (int i = 0; i < 22; i++)
        {
            Tomato nxt;
            nxt.cnt = cur.cnt + 1;
            nxt.m = cur.m + d[i][0];
            nxt.n = cur.n + d[i][1];
            nxt.o = cur.o + d[i][2];
            nxt.p = cur.p + d[i][3];
            nxt.q = cur.q + d[i][4];
            nxt.r = cur.r + d[i][5];
            nxt.s = cur.s + d[i][6];
            nxt.t = cur.t + d[i][7];
            nxt.u = cur.u + d[i][8];
            nxt.v = cur.v + d[i][9];
            nxt.w = cur.w + d[i][10];
            if (nxt.m >= m || nxt.m < 0 ||
                nxt.n >= n || nxt.n < 0 ||
                nxt.o >= o || nxt.o < 0 ||
                nxt.p >= p || nxt.p < 0 ||
                nxt.q >= q || nxt.q < 0 ||
                nxt.r >= r || nxt.r < 0 ||
                nxt.s >= s || nxt.s < 0 ||
                nxt.t >= t || nxt.t < 0 ||
                nxt.u >= u || nxt.u < 0 ||
                nxt.v >= v || nxt.v < 0 ||
                nxt.w >= w || nxt.w < 0)
                continue;
            if (vis[get_index(nxt.m, nxt.n, nxt.o, nxt.p, nxt.q, nxt.r, nxt.s, nxt.t, nxt.u, nxt.v, nxt.w)])
                continue;
            sum--;
            qe.push(nxt);
            vis[(get_index(nxt.m, nxt.n, nxt.o, nxt.p, nxt.q, nxt.r, nxt.s, nxt.t, nxt.u, nxt.v, nxt.w))] = 1;
        }
    }
    if (sum == 0)
        cout << ans;
    else
        cout << -1;
}

void input()
{
    cin >> m >> n >> o >> p >> q >> r >> s >> t >> u >> v >> w;
    sum = m * n * o * p * q * r * s * t * u * v * w;
    for (int i11 = 0; i11 < w; i11++)
        for (int i10 = 0; i10 < v; i10++)
            for (int i9 = 0; i9 < u; i9++)
                for (int i8 = 0; i8 < t; i8++)
                    for (int i7 = 0; i7 < s; i7++)
                        for (int i6 = 0; i6 < r; i6++)
                            for (int i5 = 0; i5 < q; i5++)
                                for (int i4 = 0; i4 < p; i4++)
                                    for (int i3 = 0; i3 < o; i3++)
                                        for (int i2 = 0; i2 < n; i2++)
                                            for (int i1 = 0; i1 < m; i1++)
                                            {
                                                int a;
                                                cin >> a;
                                                Tomato tt;
                                                tt.cnt = 0;
                                                tt.m = i1;
                                                tt.n = i2;
                                                tt.o = i3;
                                                tt.p = i4;
                                                tt.q = i5;
                                                tt.r = i6;
                                                tt.s = i7;
                                                tt.t = i8;
                                                tt.u = i9;
                                                tt.v = i10;
                                                tt.w = i11;
                                                if (a == 1)
                                                {
                                                    qe.push(tt);
                                                    sum--;
                                                    vis[(get_index(tt.m, tt.n, tt.o, tt.p, tt.q, tt.r, tt.s, tt.t, tt.u, tt.v, tt.w))] = 1;
                                                }
                                                else if (a == -1)
                                                {
                                                    sum--;
                                                    vis[(get_index(tt.m, tt.n, tt.o, tt.p, tt.q, tt.r, tt.s, tt.t, tt.u, tt.v, tt.w))] = 1;
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