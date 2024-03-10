#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <cstdlib>
using namespace std;

int n, r, x, y;
int visited[1001][1001];
vector<int>v[1001];
double d,ans = 0;

void input() {
    int a, b;
    cin >> n >> r >> d >> x >> y;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v[b].push_back(a);
    }
}

double dist(int a, int b, int xx, int yy) {
    return sqrt((xx - a) * (xx - a) + (yy - b) * (yy - b));
}

void solve() {
    queue<pair<int, pair<int, int>>>q;
    q.push({ 0,{y,x} });
    visited[y][x] = 1;
    while (!q.empty()) {
        int yy = q.front().second.first;
        int xx = q.front().second.second;
        int go = q.front().first;
        q.pop();
        for (int i = yy - r; i <= yy + r; i++) {  
            if (i < 0)
                continue;
            if (i > 1000)
                continue;
            for (int j = 0; j < v[i].size(); j++) {
                double dis = dist(v[i][j], i, xx, yy);
                if (dis <= r && !visited[i][v[i][j]]) {
                    double e = d;
                    for (int i = 0; i < go; i++)
                        e /= 2;
                    q.push({ go + 1,{i,v[i][j]} });
                    visited[i][v[i][j]] = 1;
                    ans += e;
                }
            }
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}