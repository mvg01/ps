#include <bits/stdc++.h>
using namespace std;

int n, sum, par[51];
char mat[51][51];
vector<tuple<int, int, int>> v;

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

void solve()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == '0')
                continue;
            if (i != j)
            {
                if (mat[i][j] <= 'Z')
                    v.push_back({mat[i][j] - 'A' + 27, i, j});
                else
                    v.push_back({mat[i][j] - 'a' + 1, i, j});
            }
            if (mat[i][j] <= 'Z')
                sum += mat[i][j] - 'A' + 27;
            else
                sum += mat[i][j] - 'a' + 1;
        }
    }
    for (int i = 0; i < 51; i++)
        par[i] = i;
    sort(v.begin(), v.end());
    int temp = 0, cnt = 0;
    for (int i = 0; i < v.size(); i++)
    {
        auto t = v[i];
        if (get_par(get<1>(t)) != get_par(get<2>(t)))
        {
            set_union(get<1>(t), get<2>(t));
            temp += get<0>(t);
            cnt++;
        }
        if (cnt == n - 1)
            break;
    }
    if (cnt == n - 1)
        cout << sum - temp;
    else
        cout << -1;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> mat[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}