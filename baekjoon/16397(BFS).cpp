#include <bits/stdc++.h>
using namespace std;

int n, t, g;
int visited[100000];
void input() {
    cin >> n >> t >> g;
}

void solve() {
    queue<pair<int, int>>q;
    q.push({ n,0 });
    visited[n] = 1;
    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();
        if (x > t)
            continue;
        if (y == g) {
            cout << x;
            return;
        }
        if (y + 1 <= 99999) {
            if (!visited[y + 1]) {
                q.push({ y + 1,x + 1 });
                visited[y + 1] = 1;
            }
        }
        int temp = y * 2;
        int len = 1;
        while (temp) {
            temp /= 10;
            len *= 10;
        }
        len /= 10;
        temp = y * 2;
        temp -= len;
        if (y * 2 <= 99999) {
            if (!visited[temp]) {
                q.push({ temp,x + 1 });
                visited[temp] = 1;
            }
        }
    }
    cout << "ANG";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}