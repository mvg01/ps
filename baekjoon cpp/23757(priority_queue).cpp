#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n, m, c;
int w[100001];
priority_queue<int>q;

void input() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        cin >> c;
        q.push(c);
    }
    for (int i = 0; i < m; i++)
        cin >> w[i];
}

void solve() {
    for (int i = 0; i < m; i++) {
        if (q.top() >= w[i]) {
            int x = q.top();
            q.pop();
            x -= w[i];
            q.push(x);
        }
        else {
            cout << 0;
            return;
        }
    }
    cout << 1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}