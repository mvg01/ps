#include <bits/stdc++.h>
using namespace std;

int n, m, v[100001], chk[100001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;

void input()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> v[i];
        q.push({v[i], i});
        chk[i] = v[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a;
        if (a == 1)
        {
            cin >> b >> c;
            chk[b] = c;
            q.push({c, b});
        }
        else
        {
            while (q.size())
            {
                b = q.top().second;
                c = q.top().first;
                if (chk[b] == c)
                {
                    cout << b << '\n';
                    break;
                }
                q.pop();
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}