#include <bits/stdc++.h>
using namespace std;

int t, n, m, a, b;
int parent[1001];

int getParent(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = getParent(parent[x]);  // 효율적인 경로 압축
}

void set_union(int x, int y) {
    int r1 = getParent(x);
    int r2 = getParent(y);
    if (r1 < r2)
        parent[r2] = r1;
    else
        parent[r1] = r2;
}

void input() {
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            set_union(a, b);
        }
        if (n - 1 == m) {
            int temp = getParent(1);
            for (int j = 2; j <= n; j++) {
                if (temp != getParent(j)) {
                    temp = -1;
                    cout << "graph\n";
                    break;
                }
            }
            if (temp != -1)
                cout << "tree\n";
        }
        else
            cout << "graph\n";
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}