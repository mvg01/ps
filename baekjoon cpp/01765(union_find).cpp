#include <bits/stdc++.h>
using namespace std;

int n, m, p[1001], ans;
vector<int> v[1001];

int getp(int x)
{
    if (x == p[x])
        return x;
    else
        return p[x] = getp(p[x]);
}

void setunion(int a, int b)
{
    a = getp(a);
    b = getp(b);
    if (a < b)
        p[b] = a;
    else
        p[a] = b;
}

void solve()
{
    for (int i = 1; i <= n; i++)
    {
        if (v[i].size() > 1)
        { // 원수의 원수는 친구다.
            for (int j = 0; j < v[i].size() - 1; j++)
                setunion(v[i][j], v[i][j + 1]);
        }
    }
    set<int> s;
    for (int i = 1; i <= n; i++)
        s.insert(getp(i));
    cout << s.size();
}

void init()
{
    for (int i = 1; i <= 1000; i++)
        p[i] = i;
}

void input()
{
    init();
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        char x;
        int a, b;
        cin >> x >> a >> b;
        if (x == 'E')
        {
            v[a].push_back(b);
            v[b].push_back(a);
        }
        else
        {
            setunion(a, b);
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