#include <bits/stdc++.h>
using namespace std;

int n, m, x, y, cnt, ans, par[1001];
vector<tuple<int, int, int>> v;
vector<pair<int, int>> res;

int get_par(int x)
{
    if (x == par[x])
        return x;
    else
        return par[x] = get_par(par[x]);
}

void set_union(int x, int y)
{
    x = get_par(x);
    y = get_par(y);
    if (x < y)
        par[y] = x;
    else
        par[x] = y;
}

void init()
{
    for (int i = 0; i < 1001; i++)
        par[i] = i;
}

void solve()
{
    sort(v.begin(), v.end());
    if (cnt >= n - 1)
    { // 이미 모두 연결
        cout << "0 0";
        return;
    }
    int ans2 = 0;
    for (int i = 0; i < v.size(); i++)
    {
        auto k = v[i];
        if (get_par(get<1>(k)) != get_par(get<2>(k)))
        {
            set_union(get<1>(k), get<2>(k));
            cnt++;
            ans2++;
            ans += get<0>(k);
            res.push_back({get<1>(k), get<2>(k)});
        }
        if (cnt == n - 1)
            break;
    }
    cout << ans << ' ' << ans2 << '\n';
    for (auto i : res)
    {
        cout << i.first << ' ' << i.second << '\n';
    }
}

void input()
{
    cin >> n >> m;
    init();
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y;
        if (get_par(x) != get_par(y))
        {
            set_union(x, y);
            cnt++;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int p;
            cin >> p;
            if (i != j)
            {
                if (i != 1 && j != 1) // 1번과는 무조건 연결되어있음(?)
                    v.push_back({p, i, j});
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