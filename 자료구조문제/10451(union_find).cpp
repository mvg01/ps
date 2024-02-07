#include <iostream>
using namespace std;

int t, n;
int parent[1001];

void init() {
    for (int i = 0; i < 1001; i++)
        parent[i] = i;
}

int getparent(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = getparent(parent[x]);
}

void set_union(int a, int b) {
    a = getparent(a);
    b = getparent(b);
    if (a < b)
        parent[b] = a;
    else
        parent[a] = b;
}

void solve() {
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (parent[i] == i)
            cnt++;
    }
    cout << cnt << '\n';
}

void input() {
    cin >> t;
    int a;
    while (t--) {
        cin >> n;
        init();
        for (int i = 1; i <= n; i++) {
            cin >> a;
            set_union(i, a);
        }
        solve();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}