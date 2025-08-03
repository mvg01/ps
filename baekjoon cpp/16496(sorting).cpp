#include <bits/stdc++.h>
using namespace std;
using ll = unsigned long long;

int n;
vector<pair<ll, string>> v;
void solve()
{
    sort(v.begin(), v.end(), greater<pair<ll, string>>());
    if (v[0].second == "0")
    {
        cout << 0;
        return;
    }
    for (auto i : v)
        cout << i.second;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s, t;
        cin >> s;
        t = s;
        int idx = 0;
        while (t.length() < 10)
            t += s; // 똑같은 수 이어붙임
        t = t.substr(0, 10);
        ll g = 0; // 가중치
        idx = 0;
        for (ll i = 1000000000; i >= 1; i /= 10)
            g += i * (t[idx++] - '0');
        v.push_back({g, s});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}