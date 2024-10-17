#include <iostream>
#include <queue>
using namespace std;

int a, k;
int visited[1000001];

void solve() {
    int res;
    queue<int>q;
    q.push(a);
    visited[a] = 1;
    while (!q.empty()) {
        int z = q.front();
        int dis = visited[z];
        q.pop();
        if (z == k) {
            res = dis - 1;
            break;
        }
        if (z * 2 <= 1000000) {
            if (!visited[z * 2]) {
                q.push(z * 2);
                visited[z * 2] = dis + 1;
            }
        }
        if (z + 1 <= 1000000) {
            if (!visited[z + 1]) {
                q.push(z + 1);
                visited[z + 1] = dis + 1;
            }
        }
    }
    cout << res;
}

void input() {
    cin >> a >> k;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}