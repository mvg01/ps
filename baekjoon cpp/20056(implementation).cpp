#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int r, c, m, d, s;
} fire;

int n, m, k;
int d[8][2] = {{-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}};
vector<fire> v;

void solve()
{
    while (k--)
    {
        vector<fire> temp[51][51];
        for (auto i : v)
        { // 0~n-1 인덱스 컨트롤
            int dy = ((i.r + d[i.d][0] * i.s) % n + n) % n;
            int dx = ((i.c + d[i.d][1] * i.s) % n + n) % n;
            temp[dy][dx].push_back(i);
        }
        v.clear();
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (temp[i][j].size() > 1)
                {
                    bool odd = 0, even = 0;
                    int m_sum = 0, s_sum = 0;
                    for (auto p : temp[i][j])
                    {
                        m_sum += p.m;
                        s_sum += p.s;
                        if (p.d % 2)
                            odd = 1;
                        else
                            even = 1;
                    }
                    m_sum /= 5;
                    s_sum /= temp[i][j].size();
                    if (m_sum < 1)
                        continue;
                    fire f;
                    f.r = i;
                    f.c = j;
                    f.m = m_sum;
                    f.s = s_sum;
                    if (odd && even)
                    { // 1,3,5,7 파이어볼 나누기
                        for (int i = 1; i < 8; i += 2)
                        {
                            f.d = i;
                            v.push_back(f);
                        }
                    }
                    else
                    { // 0,2,4,6
                        for (int i = 0; i < 8; i += 2)
                        {
                            f.d = i;
                            v.push_back(f);
                        }
                    }
                }
                else if (temp[i][j].size() == 1) // 나눠지지 않는 그냥 파이어볼
                {
                    fire f;
                    f.r = i;
                    f.c = j;
                    f.m = temp[i][j][0].m;
                    f.s = temp[i][j][0].s;
                    f.d = temp[i][j][0].d;
                    v.push_back(f);
                }
            }
        }
    }
    int ans = 0;
    for (auto i : v)
        ans += i.m;
    cout << ans;
}

void input()
{
    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        fire p;
        cin >> p.r >> p.c >> p.m >> p.s >> p.d;
        p.r--;
        p.c--;
        v.push_back(p);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}