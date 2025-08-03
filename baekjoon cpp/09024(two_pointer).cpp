#include <bits/stdc++.h>
using namespace std;

int t, n, k, x;
vector<int>v;

void input() {
    cin >> t;
    while (t--) {
        v.clear();
        cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> x;
            v.push_back(x);
        }
        sort(v.begin(), v.end());
        int left = 0, right = n - 1, dif = 2000000000, ans = 0;
        while (left < right) {
            int sum = v[left] + v[right];
            if (sum - k < 0) {
                left++;
                if (dif > (sum - k) * -1) {
                    ans = 1;
                    dif = (sum - k) * -1;
                }
                else if (dif == (sum - k) * -1)
                    ans++;
            }
            else {
                right--;
                if (dif > sum - k) {
                    ans = 1;
                    dif = sum - k;
                }
                else if (dif == sum - k)
                    ans++;
            }
        }
        cout << ans << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}