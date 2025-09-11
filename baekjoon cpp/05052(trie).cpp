#include <bits/stdc++.h>
using namespace std;

int n, cnt = 2;
const int MX = 10000 * 10 + 1;
bool chk[MX], ans;
int nxt[MX][10];
vector<string> v;

void insert(string s)
{
    int cur = 1;
    for (auto i : s)
    {
        if (nxt[cur][i - '0'] == -1)
        {
            nxt[cur][i - '0'] = cnt++;
        }
        cur = nxt[cur][i - '0'];
        if (chk[cur])
            ans = 1;
    }
    chk[cur] = 1;
}

void init()
{
    for (int i = 0; i < MX; i++)
    {
        for (int j = 0; j < 10; j++)
            nxt[i][j] = -1;
        chk[i] = 0;
    }
    ans = 0;
    v.clear();
    cnt = 2;
}

bool com(string a, string b)
{
    return a.size() < b.size();
}

void solve()
{
    sort(v.begin(), v.end(), com);
    for (int i = 0; i < n; i++)
        insert(v[i]);
    if (!ans)
        cout << "YES\n";
    else
        cout << "NO\n";
}

void input()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n;
        init();
        for (int i = 0; i < n; i++)
        {
            string s;
            cin >> s;
            v.push_back(s);
        }
        solve();
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}