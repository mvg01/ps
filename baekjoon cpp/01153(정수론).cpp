#include <bits/stdc++.h>
using namespace std;

int n, a[1000001];
vector<int>v;

void f(int x) {  // 투포인터로 쌍 찾기
    int s = 0, e = v.size() - 1;
    while (s <= e) {
        if (v[s] + v[e] < x)
            s++;
        else if (v[s] + v[e] > x)
            e--;
        else {
            if (n % 2 == 1) 
                cout << "2 3 ";
            else 
                cout << "2 2 ";
            cout << v[s] << ' ' << v[e];
            return;
        }
    }
    cout << -1;
}

void solve() {
    for (int i = 1; i <= 1000000; i++) a[i] = i;
    for (int i = 2; i <= 1000; i++) {
        if (a[i] == 0)
            continue;
        for (int j = i * i; j <= 1000000; j += i)
            a[j] = 0;
    }
    for (int i = 2; i <= 1000000; i++)
        if (a[i] == i) v.push_back(i);
    if (n < 8)
        cout << -1;
    else if (n % 2) {
        f(n - 5);
    }
    else {
        f(n - 4);
    }
}

void input() {
    cin >> n;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}