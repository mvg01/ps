#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t, a, b, res = 0;
int visited[5000001];
void input() {
    cin >> t >> a >> b;
}
    
void solve() {
    queue<pair<int, bool>>q;
    q.push({ 0,false });
    visited[0] = 1;
    while (!q.empty()) {
        int x = q.front().first;
        bool w = q.front().second;  // 물 마심 여부
        res = max(res, x);
        q.pop();
        if (x + a <= t) {
            if (!visited[x + a]) {
                visited[x + a] = 1;
                q.push({ x + a,w });
            }
        }
        if (x + b <= t) {
            if (!visited[x + b]) {
                visited[x + b] = 1;
                q.push({ x + b,w });
            }
        }
        if (!visited[x / 2] && w == 0) {
            q.push({ x / 2,1 });
            visited[x / 2] = 1;
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}