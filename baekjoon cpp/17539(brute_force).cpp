#include <bits/stdc++.h>
using namespace std;

int n, ans = 1e9;
vector<pair<string, int>> v;
int change[11];

void solve()
{
    for (int i = 0; i < n; i++)
    {
        int len = v[i].first.length();
        for (int j = 1; j < len; j++)
        {
            if (v[i].first[j - 1] != v[i].first[j])
                change[v[i].second]++;
        }
    }
    sort(v.begin(), v.end());
    do
    {
        int temp = change[v[0].second];
        for (int i = 1; i < n; i++)
        {
            if (v[i - 1].first.back() != v[i].first.front())
                temp++;
            temp += change[v[i].second];
        }
        ans = min(ans, temp);
    } while (next_permutation(v.begin(), v.end()));
    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back({s, i});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}