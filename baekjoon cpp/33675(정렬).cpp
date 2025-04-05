#include <bits/stdc++.h>
using namespace std;

// x = x0 - y/m

int n;
vector<pair<double, string>> v;
void solve()
{
    sort(v.begin(), v.end());
    for (auto i : v)
        cout << i.second << '\n';
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        double a, b, c;
        string s;
        cin >> a >> b >> c >> s;
        if (b * c >= 0) // x축과 닿을 수 없는
            continue;
        double r = a - (b / c); // x축과 닿는 x 좌표 구하는 공식 사용
        v.push_back({r, s});
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}