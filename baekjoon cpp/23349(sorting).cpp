#include <bits/stdc++.h>
using namespace std;

int n, idx, ans;
map<string, bool> name;
map<string, int> indx;
map<int, string> place;
int mat[11][50001];
vector<tuple<int, string, pair<int, int>>> v;

bool com(tuple<int, string, pair<int, int>> a, tuple<int, string, pair<int, int>> b)
{
    if (get<0>(a) > get<0>(b))
        return 1;
    else if (get<0>(a) < get<0>(b))
        return 0;
    else
    {
        if (get<1>(a) < get<1>(b))
            return 1;
        else if (get<1>(a) > get<1>(b))
            return 0;
        else
        {
            return get<2>(a).first < get<2>(b).first;
        }
    }
}

void solve()
{
    for (int i = 0; i < idx; i++)
    {
        int mx = 0, s = 0, e = 0;
        for (int j = 0; j < 50001; j++)
        {
            if (mat[i][j] > mx)
            {
                mx = mat[i][j];
                s = j;
                e = j + 1;
            }
            else if (mx != 0 && mat[i][j] == mx)
            {
                if (e == j)
                    e = j + 1;
            }
        }
        v.push_back({mx, place[i], make_pair(s, e)});
    }
    sort(v.begin(), v.end(), com);
    cout << get<1>(v[0]) << ' ' << get<2>(v[0]).first << ' ' << get<2>(v[0]).second;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b;
        int c, d;
        cin >> a >> b >> c >> d;
        if (name[a])
            continue;
        name[a] = 1;
        if (indx.count(b))
        {
            int t = indx[b];
            for (int j = c; j < d; j++)
                mat[t][j]++;
        }
        else
        {
            indx[b] = idx++;
            place[idx - 1] = b;
            for (int j = c; j < d; j++)
                mat[idx - 1][j]++;
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