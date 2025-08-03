#include <bits/stdc++.h>
using namespace std;

int n;
struct st
{
    string name, school, win;
    int shake, acpc;
    st(string a, string b, string c, int d, int e)
    {
        name = a;
        school = b;
        win = c;
        shake = d;
        acpc = e;
    }
};
vector<st> v;

bool com(const st &a, const st &b)
{
    return a.acpc < b.acpc;
}
bool com2(const st &a, const st &b)
{
    return a.name < b.name;
}

void solve()
{
    sort(v.begin(), v.end(), com);
    int cnt = min(10, (int)v.size());
    vector<st> vv(v.begin(), v.begin() + cnt);
    sort(vv.begin(), vv.end(), com2);
    cout << cnt << '\n';
    for (int i = 0; i < cnt; i++)
        cout << vv[i].name << '\n';
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string a, b, c;
        int d, e;
        cin >> a >> b >> c >> d >> e;
        st x(a, b, c, d, e);
        if (b == "hewhak")
            continue;
        if (c == "winner")
            continue;
        if (d <= 3 && d != -1)
            continue;
        v.push_back(x);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}