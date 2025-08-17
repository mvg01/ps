#include <bits/stdc++.h>
using namespace std;

typedef struct
{
    int a, c, g, t;
} cnt;

cnt k;
int n, p, a, c, g, t, ans = 0;
string s;

void solve()
{
    k.a = 0, k.c = 0, k.g = 0, k.t = 0;
    for (int i = 0; i < p; i++)
    {
        if (s[i] == 'A')
            k.a++;
        if (s[i] == 'C')
            k.c++;
        if (s[i] == 'G')
            k.g++;
        if (s[i] == 'T')
            k.t++;
    }
    for (int i = p; i < n; i++)
    {
        if (k.a >= a && k.c >= c && k.g >= g && k.t >= t)
            ans++;
        if (s[i] == 'A')
            k.a++;
        if (s[i] == 'C')
            k.c++;
        if (s[i] == 'G')
            k.g++;
        if (s[i] == 'T')
            k.t++;
        if (s[i - p] == 'A')
            k.a--;
        if (s[i - p] == 'C')
            k.c--;
        if (s[i - p] == 'G')
            k.g--;
        if (s[i - p] == 'T')
            k.t--;
    }
    if (k.a >= a && k.c >= c && k.g >= g && k.t >= t)
        ans++;
    cout << ans;
}

void input()
{
    cin >> n >> p >> s >> a >> c >> g >> t;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}