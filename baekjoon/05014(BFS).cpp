#include <iostream>
#include <queue>
using namespace std;

int f, s, g, u, d, ans = -1;
int visited[1000001] = { 0 };

void solve() {
    queue<int>q;
    q.push(s);
    visited[s] = 1;
    while (!q.empty()) {
        int next = q.front();
        int cnt = visited[next];
        q.pop();
        if (next == g) {
            ans = cnt - 1;
            break;
        }
        if (next + u <= f) {
            if (!visited[next + u]) {
                q.push(next + u);
                visited[next + u] = cnt + 1;
            }
        }
        if (next - d >= 1) {
            if (!visited[next - d]) {
                q.push(next - d);
                visited[next - d] = cnt + 1;
            }
        }
    }
}

void input() {
    cin >> f >> s >> g >> u >> d;
    solve();
    if (ans == -1)
        cout << "use the stairs";
    else
        cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}