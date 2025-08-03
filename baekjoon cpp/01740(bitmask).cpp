#include <iostream>
using namespace std;

bool bit[34];
long long n;
void input() {
    cin >> n;
}

void solve() {
    int idx = 0;
    while (n > 1) {
        bit[idx++] = n % 2;
        n /= 2;
    }
    bit[idx] = 1;
    long long ans = 0;

    for (int i = 0; i <= idx; i++) {
        long long plus = 1;
        if (bit[i]) {
            for (int j = 0; j < i; j++) {
                plus *= 3;
            }
            ans += plus;
        }
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}