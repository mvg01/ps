#include <bits/stdc++.h>
using namespace std;

int n, m;
priority_queue<pair<int, int>> q1;
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q2;
map<pair<int, int>, bool> um;
int chk[100001];

void solve()
{
    for (int i = 0; i < m; i++)
    {
        string s;
        int a, b;
        cin >> s;
        if (s[0] == 'r')
        {
            cin >> a;
            int ans = 0;
            if (a == -1)
            {
                while (1)
                {
                    if (um[{q2.top().second, q2.top().first}] != 0)
                    {
                        ans = q2.top().second;
                        cout << ans << '\n';
                        break;
                    }
                    else
                        q2.pop();
                }
            }
            else
            {
                while (1)
                {
                    if (um[{q1.top().second, q1.top().first}] != 0)
                    {
                        ans = q1.top().second;
                        cout << ans << '\n';
                        break;
                    }
                    else
                        q1.pop();
                }
            }
        }
        else if (s[0] == 'a')
        {
            cin >> a >> b;
            if (chk[a])
            {
                um[{a, chk[a]}] = 0;
                chk[a] = b;
                um[{a, b}] = 1;
            }
            else
            {
                chk[a] = b;
                um[{a, b}] = 1;
            }
            q1.push({b, a});
            q2.push({b, a});
        }
        else
        {
            cin >> a;
            um[{a, chk[a]}] = 0;
        }
    }
}

void input()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (chk[a])
        {
            um[{a, chk[a]}] = 0;
            chk[a] = b;
            um[{a, b}] = 1;
        }
        else
        {
            chk[a] = b;
            um[{a, b}] = 1;
        }
        q1.push({b, a});
        q2.push({b, a});
    }
    cin >> m;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}