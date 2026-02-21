#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[6], o;
ll ans;
char d[6] = {'P', 'C', 'V', 'S', 'G', 'F'};
vector<string> v;
void solve()
{
    for (auto i : v)
    {
        int l = i.length();
        ll temp = 1e17;
        bool no = 0;
        char x = i[0];
        if (x == 'O')
            no = 1;
        for (int j = 1; j < l; j++)
            if (x != i[j])
                no = 1;
        if (!no)
        {
            for (int j = 0; j < 6; j++)
            {
                if (d[j] == x)
                    temp = min(temp, (ll)a[j] * l);
            }
        }
        temp = min(temp, (ll)o * l);
        ans += temp;
    }
    cout << ans;
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        v.push_back(s);
    }
    for (int i = 0; i < 6; i++)
        cin >> a[i];
    cin >> o;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}