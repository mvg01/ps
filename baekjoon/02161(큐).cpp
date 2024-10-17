#include <iostream>
#include <queue>
using namespace std;

int n;
queue<int>q;
void input() {
    cin >> n;
}

void solve() {
    for (int i = 1; i <= n; i++)
        q.push(i);
    while (1) {
        cout << q.front() << ' ';
        q.pop();
        if (q.empty())
            break;
        int temp = q.front();
        q.pop();
        q.push(temp);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}