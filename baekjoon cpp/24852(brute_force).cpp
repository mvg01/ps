#include <iostream>
#include <cmath>
#include <string>
#include <algorithm>
using namespace std;

long long a, b;
void input() {
    cin >> a >> b;
}
void solve() {
    int cnt = 0;
    for (long long i = 1; i <= 1000000; i++) {
        if (i * i > b)
            break;
        if (i * i >= a) {
            long long temp = i * i, m;
            if (temp % 10 == 0)  // 뒤집은 수가 0으로 시작함
                continue;
            string s = to_string(temp);
            reverse(s.begin(), s.end());
            m = stoll(s);
            long long x = sqrt(m);
            if (x * x == m) 
                cnt++;
        }
    }
    cout << cnt;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}