#include <iostream>
#include <queue>
using namespace std;

int n, k;
queue<int>q;
void input() {
    cin >> n >> k;
}

void solve() {
    for (int i = 1; i <= n; i++)
        q.push(i);
    while (1) {
        int x = q.front();
        q.pop();
        for (int i = 0; i < k - 1; i++) {
            if (!q.empty())
                q.pop();
            else {
                cout << x;
                return;
            }
        }
        q.push(x);
        if (q.size() < k) {
            cout << q.front();
            break;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}