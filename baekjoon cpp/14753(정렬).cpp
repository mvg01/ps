#include <bits/stdc++.h>
using namespace std;

int n, x;
vector<int>a, b;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> x;
        if (x > 0)
            a.push_back(x);
        else if (x < 0)
            b.push_back(x);
    }
}

bool c(int a, int b) {
    return a > b;
}

void solve() {
    for (int i = 0; i < 3; i++) {
        a.push_back(0);
        b.push_back(0);
    }
    if (!a.empty()) sort(a.begin(), a.end(), c);
    if (!b.empty()) sort(b.begin(), b.end());
   
    vector<int>list;  // 정답 가능한 리스트
    list.push_back({ a[0] * a[1] });
    list.push_back({ b[0] * b[1] });
    list.push_back({ a[0] * b[0] * b[1] });
    list.push_back({ b[0] * b[1] * a[0] });
    list.push_back({ a[0] * a[1] * a[2] });
    sort(list.begin(), list.end(), c);
    cout << list[0];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}