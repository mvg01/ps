#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
using namespace std;

int v, e;
vector<tuple<int, int, int>>mat;
int parent[10001];

void input() {
    int a, b, c;
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b >> c;
        mat.push_back({ a,b,c });
    }
}

void init() {
    for (int i = 1; i <= v; i++)
        parent[i] = i;
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

bool com(tuple<int, int, int>a,tuple<int, int, int>b) {
    return get<2>(a) < get<2>(b);
}

void solve() {
    int res = 0, cnt = 0;
    sort(mat.begin(), mat.end(), com);
    init();

    for (int i = 0; i < e; i++) {
        if (!same_parent(get<0>(mat[i]), get<1>(mat[i]))) {  // 사이클 발생하지 않으면
            set_union(get<0>(mat[i]), get<1>(mat[i]));
            cnt++;
            res += get<2>(mat[i]);
        }
        if (cnt == v - 1)
            break;
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}