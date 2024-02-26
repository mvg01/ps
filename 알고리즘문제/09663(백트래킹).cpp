#include <iostream>
using namespace std;

int ans = 0, n;
bool visited1[16];  // 1. 행에 대한 방문 여부
bool visited2[31];  // 2. 왼쪽 아래에서 오른쪽 위 대각선 방문 여부 -> y좌표(c) + x좌표(i)
bool visited3[31];  // 3. 왼쪽 위에서 오른쪽 아래 대각선 방문 여부 -> y좌표(c) - x좌표(i) + n - 1

void solve(int c) {
    if (c == n) {
        ans++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!visited1[i] && !visited2[c + i] && !visited3[c - i + n - 1]) {
            visited1[i] = 1;
            visited2[c + i] = 1;
            visited3[c - i + n - 1] = 1;
            solve(c + 1);
            visited1[i] = 0;
            visited2[c + i] = 0;
            visited3[c - i + n - 1] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    solve(0);
    cout << ans;
}