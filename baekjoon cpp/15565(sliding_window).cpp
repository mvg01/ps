#include <iostream>
#include <queue>
using namespace std;

int n, k;
int a[1000001];
void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
}

void solve() {
    int ans = 1000001, cnt = 0;
    deque<int>lion;
    for (int i = 1; i <= n; i++) {
        if (a[i] == 1) {
            cnt++;
            lion.push_back(i);
        }
        if (cnt == k) {
            int temp = i - lion.front() + 1;
            lion.pop_front();
            ans = min(ans, temp);
            cnt--;
        }
    }
    if (ans == 1000001)
        cout << -1;
    else
        cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}