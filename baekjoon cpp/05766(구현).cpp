#include <bits/stdc++.h>
using namespace std;

int n, m, x;
int cnt[10001];
vector<pair<int, int>> v;
void solve()
{
}

void input()
{
    while (1)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        for (int i = 1; i < 10001; i++)
            cnt[i] = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                cin >> x;
                cnt[x]++;
            }
        }
        vector<pair<int, int>> v;
        for (int i = 1; i < 10001; i++)
        {
            if (cnt[i] != 0)
                v.push_back({cnt[i], i});
        }
        sort(v.begin(), v.end());
        x = v[v.size() - 2].first;
        for (auto i : v)
        {
            if (i.first == x)
                cout << i.second << ' ';
        }
        cout << '\n';
        v.clear();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}