#include <bits/stdc++.h>
using namespace std;

int n, q;
string s;
void solve()
{
}

void input()
{
    cin >> n >> s >> q;
    while (q--)
    {
        int a, b;
        cin >> a >> b;
        string temp = s.substr(a - 1, b - a + 1);
        int len = temp.length(), ans = 0;
        for (int i = 1; i < len; i++)
        {
            string l = temp.substr(0, i);
            string r = temp.substr(i, len - i);
            int cnt = 0, llen = l.length(), rlen = r.length();
            if (llen <= rlen)
            {
                for (int j = 0; j < llen; j++)
                {
                    if (l[llen - j - 1] == r[j])
                        cnt++;
                }
            }
            else
            {
                for (int j = 0; j < rlen; j++)
                {
                    if (r[rlen - j - 1] == l[llen - rlen + j])
                        cnt++;
                }
            }
            ans = max(ans, cnt);
        }
        cout << ans << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}