#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int n, a[100001];
ll ans = -1e15, s[100001];
/*
해결 아이디어: 팀은 당연히 양수점수인 팀원이 많으면 좋다.
하지만 음수정수인 팀원이 포함되어도 팀원수로 곱해지는 과정에서 전체 팀 점수가
더 효율적이게 될 수 있다. 팀을 두 팀으로 나누어 전체 점수를 계산한다.
*/


void solve() {
    ll sum = 0;
    sort(a, a + n, greater<int>());  // 내림차순 정렬
    s[0] = a[0];
    for (int i = 1; i < n; i++)
        s[i] = s[i - 1] + a[i];
    for (int i = 0; i < n; i++) {
        ll temp = sum + a[i];
        temp *= (i + 1);
        temp += s[n - 1] - s[i];
        ans = max(ans, temp);
        sum += a[i];
    }
    cout << ans;
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