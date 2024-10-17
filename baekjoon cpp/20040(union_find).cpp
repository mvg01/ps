#include <iostream>
using namespace std;

int parent[500001];
int n, m, cnt = 1, ans = 1000000;

int getParent(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = getParent(parent[x]);
}

void set_union(int x, int y) {
    int r1 = getParent(x);
    int r2 = getParent(y);
    if (r1 < r2) {
        parent[r2] = r1;
    }
    else {
        parent[r1] = r2;
        if (r1 == r2)  //사이클이 생기는 순간 기록
            ans = min(ans, cnt);  
    }
    cnt++;
}

void input() {
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        parent[i] = i;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        set_union(a, b);
    }
    if (ans != 1000000)
        cout << ans;
    else
        cout << 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}