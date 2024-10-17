#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

int t, n;
int a[10005];
int v[10005];

bool c(int i, int j) {
    return i > j;
}

void input() {
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) cin >> a[i];
        sort(a, a + n, c);  // 내림차순
        int mid = n / 2, idx = 1, res = 0;

        v[mid] = a[0];
        for (int i = 1; i <= mid; i++) {  //v[mid] 부터 왼,오로 갈라지면서 값을 채운다.
            v[mid + i] = a[idx++];
            v[mid - i] = a[idx++];
        }
        if (n % 2 == 0)
            v[0] = a[n - 1];

        int left, right;
        idx = 0;
        for (int i = mid; i >= 1; i--) {
            left = v[i] - v[i - 1];
            if (n % 2 == 0 && mid + idx + 1 == n)
                right = 0;
            else
                right = v[mid + idx] - v[mid + idx + 1];
            res = max(res, left);
            res = max(res, right);
            idx++;
        }
        res = max(res, abs(v[0] - v[n - 1]));  // 첫 통나무와 인접한 마지막 통나무
        cout << res << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}