#include <bits/stdc++.h>
using namespace std;
using ll = long long;

// n은 3 r은 2라고 할 때
// ABCA를 뽑으면 1짝, ABCAAB를 뽑으면 2짝 완성

ll n, r;
void solve() {
    cout << n + r * 2 - 1;
}

void input() {
    cin >> n >> r;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}