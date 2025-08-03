#include <bits/stdc++.h>
using namespace std;

int n, a[300001];

void input() {
    cin >> n;
    n *= 3;
    for (int i = 0; i < n; i++) 
        cin >> a[i];   
}

void solve() {
    sort(a, a + n);
    n /= 3;
    cout << a[n * 2 - 1] - a[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}