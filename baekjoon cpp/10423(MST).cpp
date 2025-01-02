#include <bits/stdc++.h>
using namespace std;

int n, m, k;
int city[1001];
vector<tuple<int, int, int>>mat;
int parent[10001];

void init() {
    for (int i = 1; i <= n; i++)
        parent[i] = i;
    for (int i = 0; i < k; i++)  // 발전소의 parent는 모두 0으로
        parent[city[i]] = 0;
}

int get_parent(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = get_parent(parent[x]);
}

void set_union(int a, int b) {
    int aa = get_parent(a);
    int bb = get_parent(b);
    if (aa > bb)
        parent[aa] = bb;
    else
        parent[bb] = aa;
}

bool same_parent(int a, int b) {
    int aa = get_parent(a);
    int bb = get_parent(b);
    if (aa == bb)
        return 1;
    else
        return 0;
}

bool com(tuple<int, int, int>a, tuple<int, int, int>b) {
    return get<2>(a) < get<2>(b);
}

void solve() {
    int res = 0, cnt = 0;
    sort(mat.begin(), mat.end(), com);
    init();
    for (int i = 0; i < m; i++) {
        if (!same_parent(get<0>(mat[i]), get<1>(mat[i]))) { 
            set_union(get<0>(mat[i]), get<1>(mat[i]));
            cnt++;
            res += get<2>(mat[i]);
        }
        if (cnt == n - k)
            break;
    }
    cout << res;
}

void input() {
    int a, b, c;
    cin >> n >> m >> k;
    for (int i = 0; i < k; i++) cin >> city[i];
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        mat.push_back({ a,b,c });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}