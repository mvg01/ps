#include <bits/stdc++.h>
using namespace std;

int n, A, B, C, a, b, c;
bool vis[2001][2001];                       // a와 b의 방문처리
pair<char, pair<int, int>> mat[2001][2001]; // 경로 역추적 용

void solve()
{
    queue<tuple<int, int, int>> q;
    q.push({A, B, C});
    vis[A][B] = 1;
    mat[A][B].first = 'E'; // 시작 경로, 임의로 'E'로..
    while (q.size())
    {
        int a1 = get<0>(q.front());
        int b1 = get<1>(q.front());
        int c1 = get<2>(q.front());
        q.pop();
        if (a1 == n && b1 == n)
        {
            vector<char> ans;
            while (mat[a1][b1].first != 'E')
            {
                int a2 = a1, b2 = b1;
                ans.push_back(mat[a1][b1].first);
                a1 = mat[a2][b2].second.first;
                b1 = mat[a2][b2].second.second;
            }
            cout << ans.size() << '\n';
            reverse(ans.begin(), ans.end());
            for (auto i : ans)
                cout << i;
            return;
        }
        if (a1 + a < 2 * n && c1 - a > 0)
        { // 궁기의 공격
            int a2 = a1 + a;
            int c2 = c1 - a;
            int b2 = n * 3 - (a2 + c2);
            if (!vis[a2][b2])
            {
                q.push({a2, b2, c2});
                vis[a2][b2] = 1;
                mat[a2][b2].first = 'A';
                mat[a2][b2].second = {a1, b1};
            }
        }
        if (b1 + b < 2 * n && a1 - b > 0)
        { // 도올의 공격
            int b2 = b1 + b;
            int a2 = a1 - b;
            int c2 = n * 3 - (b2 + a2);
            if (!vis[a2][b2])
            {
                q.push({a2, b2, c2});
                vis[a2][b2] = 1;
                mat[a2][b2].first = 'B';
                mat[a2][b2].second = {a1, b1};
            }
        }
        if (c1 + c < 2 * n && b1 - c > 0)
        { // 혼돈의 공격
            int c2 = c1 + c;
            int b2 = b1 - c;
            int a2 = n * 3 - (c2 + b2);
            if (!vis[a2][b2])
            {
                q.push({a2, b2, c2});
                vis[a2][b2] = 1;
                mat[a2][b2].first = 'C';
                mat[a2][b2].second = {a1, b1};
            }
        }
    }
    cout << -1;
}

void input()
{
    cin >> n >> A >> B >> C >> a >> b >> c;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}