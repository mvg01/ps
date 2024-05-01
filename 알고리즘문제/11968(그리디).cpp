#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[50001];
priority_queue<int, vector<int>, greater<int>>b;
bool chk[100001];
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i]; 
        chk[a[i]] = 1;
    }
}

void solve() {
    int res = 0;
    for (int i = 1; i <= n * 2; i++)
        if (!chk[i]) b.push(i);
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        while (!b.empty()) {
            int t = b.top();
            if (a[i] < t) {
                res++;
                b.pop();
                break;
            }
            b.pop();
        }
        if (b.empty())
            break;
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}
