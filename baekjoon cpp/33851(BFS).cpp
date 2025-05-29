#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, p;
int dis[2001][2001];
<<<<<<< HEAD
vector<int> mat[2001];

void solve()
{
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
    {
        q.push({i, 0});
        while (q.size())
        {
            int nxt = q.front().first;
            int w = q.front().second;
            q.pop();
            for (int k : mat[nxt])
            {
                if (dis[i][k] > w + 1)
                {
                    dis[i][k] = w + 1;
                    q.push({k, w + 1});
=======
vector<int>mat[2001];

void solve() {
    queue<pair<int, int>>q;
    for (int i = 1; i <= n; i++) {
        q.push({ i,0 });
        while (q.size()) {
            int nxt = q.front().first;
            int w = q.front().second;
            q.pop();
            for (int k : mat[nxt]) {
                if (dis[i][k] > w + 1) {
                    dis[i][k] = w + 1;
                    q.push({ k,w + 1 });
>>>>>>> 5b0c2ec063f441526a918f3d23b2df08cb4bdae9
                }
            }
        }
    }
<<<<<<< HEAD
    for (int i = 0; i < p; i++)
    {
        int u, v;
        cin >> u >> v;
        int ans = INF;
        for (int j = 1; j <= n; j++)
        {
            if (dis[j][u] == INF || dis[j][v] == INF)
=======
    for (int i = 0; i < p; i++) {
        int u, v;
        cin >> u >> v;
        int ans = INF;
        for (int j = 1; j <= n; j++) {
            if (dis[j][u] == INF || dis[j][v] == INF) 
>>>>>>> 5b0c2ec063f441526a918f3d23b2df08cb4bdae9
                continue;
            int temp = max(dis[j][u], dis[j][v]);
            ans = min(ans, temp);
        }
<<<<<<< HEAD
        if (ans == INF)
            ans = -1;
=======
        if (ans == INF) ans = -1;
>>>>>>> 5b0c2ec063f441526a918f3d23b2df08cb4bdae9
        cout << ans << '\n';
    }
}

<<<<<<< HEAD
void input()
{
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
=======
void input() {
    cin >> n >> m >> p;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
>>>>>>> 5b0c2ec063f441526a918f3d23b2df08cb4bdae9
            if (i != j)
                dis[i][j] = INF;
        }
    }
<<<<<<< HEAD
    for (int i = 0; i < m; i++)
    {
=======
    for (int i = 0; i < m; i++) {
>>>>>>> 5b0c2ec063f441526a918f3d23b2df08cb4bdae9
        int u, v;
        cin >> u >> v;
        mat[u].push_back(v);
    }
}

<<<<<<< HEAD
int main()
{
=======
int main() {
>>>>>>> 5b0c2ec063f441526a918f3d23b2df08cb4bdae9
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}