#include <bits/stdc++.h>
using namespace std;

/*
도움이 되는 반례
11
1 2 4 8 16 32 64 128 256 512 1024

ans:2048
*/

int n, a[1001], sum[1001]; // 누적 합
void solve() {
    sort(a, a + n);
    sum[0] = a[0];
    if (a[0] >= 2) {  // 가장 작은 추가 2 이상이면 답은 무조건 1
        cout << 1;
        return;
    }
    // sum 안의 수가 0번 인덱스 추 부터 i 인덱스의 추로 가능한 범위가 된다..
    for (int i = 1; i < n; i++) {
        if (sum[i - 1] + 1 < a[i]) {
            cout << sum[i - 1] + 1;
            return;
        }
        sum[i] = sum[i - 1] + a[i];
    }
    cout << sum[n - 1] + 1;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}