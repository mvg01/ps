#include <bits/stdc++.h>
using namespace std;

int v[3];
bool vis[201][201][201];
vector<int> ans;

void solve()
{
    queue<tuple<int, int, int>> q;
    q.push({0, 0, v[2]});
    int from[] = {0, 0, 1, 1, 2, 2};
    int to[] = {1, 2, 0, 2, 0, 1};
    while (q.size())
    {
        int a = get<0>(q.front());
        int b = get<1>(q.front());
        int c = get<2>(q.front());
        int abc[3] = {a, b, c};
        q.pop();
        if (vis[a][b][c])
            continue;
        else
            vis[a][b][c] = 1;
        if (a == 0)
            ans.push_back(c);
        for (int i = 0; i < 6; i++)
        {
            int f = from[i];
            int t = to[i];
            int next_abc[3] = {a, b, c};
            if (abc[f] > v[t] - abc[t])
            {
                int move = v[t] - abc[t];
                next_abc[f] -= move;
                next_abc[t] += move;
                q.push({next_abc[0], next_abc[1], next_abc[2]});
            }
            else
            {
                int move = abc[f];
                next_abc[f] -= move;
                next_abc[t] += move;
                q.push({next_abc[0], next_abc[1], next_abc[2]});
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto i : ans)
        cout << i << ' ';
}

void input()
{
    for (int i = 0; i < 3; i++)
        cin >> v[i];
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}