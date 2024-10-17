#include <iostream>
#include <vector>
#include <queue>
#define INF 999999999
using namespace std;

int n, ans;
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
int dis[126][126];
vector<int>mat[126];

void solve() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) 
            dis[i][j] = INF;   
    }
    priority_queue <pair<int, pair<int, int>>>pq;
    pq.push({ -mat[0][0],{0,0} });
    dis[0][0] = mat[0][0];
    while (!pq.empty()) {
        int distance = -pq.top().first;
        int yy = pq.top().second.first;
        int xx = pq.top().second.second;
        pq.pop();
        for (int i = 0; i < 4; i++) {
            int y = yy + dy[i];
            int x = xx + dx[i];
            if (y >= n || y < 0 || x >= n || x < 0)
                continue;
            if (dis[y][x] > distance + mat[y][x]) {
                pq.push({ -(distance + mat[y][x]),{y,x} });
                dis[y][x] = distance + mat[y][x];
            }
        }
    }
}

void input() {
    int x;
    for (int t = 1; ; t++) {
        cin >> n;
        if (n == 0)
            break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> x;
                mat[i].push_back(x);
            }
        }
        solve();
        ans = dis[n - 1][n - 1];
        cout << "Problem " << t << ": " << ans << '\n';
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++)
                mat[i].clear();
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}