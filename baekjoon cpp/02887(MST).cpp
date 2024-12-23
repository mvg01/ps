#include <bits/stdc++.h>
using namespace std;

int n;
vector<pair<int, int>>x_list;
vector<pair<int, int>>y_list;
vector<pair<int, int>>z_list;
vector<tuple<int, int, int>>mat;
int parent[100001];

bool com(tuple<int, int, int>a, tuple<int, int, int>b) {
    return get<2>(a) < get<2>(b);
}

void init() {
    for (int i = 1; i <= n; i++)
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

void solve() {
    // 간선후보를 정점들의 x,y,z 값으로 각각 정렬하고
    // 그들의 차이로 가중치를 정해준다. 
    sort(x_list.begin(), x_list.end());
    sort(y_list.begin(), y_list.end());
    sort(z_list.begin(), z_list.end());
    for (int i = 0; i < x_list.size() - 1; i++) 
        mat.push_back({ x_list[i].second, x_list[i + 1].second, x_list[i + 1].first - x_list[i].first });
    for (int i = 0; i < y_list.size() - 1; i++)
        mat.push_back({ y_list[i].second, y_list[i + 1].second, y_list[i + 1].first - y_list[i].first });
    for (int i = 0; i < z_list.size() - 1; i++)
        mat.push_back({ z_list[i].second, z_list[i + 1].second, z_list[i + 1].first - z_list[i].first });

    int cnt = 0, ans = 0;
    sort(mat.begin(), mat.end(), com);
    init();
    for (int i = 0; i < mat.size(); i++) {
        if (!same_parent(get<0>(mat[i]), get<1>(mat[i]))) {
            set_union(get<0>(mat[i]), get<1>(mat[i]));
            ans += get<2>(mat[i]);
            cnt++;
        }
        if (cnt == n - 1)
            break;
    }
    cout << ans;
}

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        x_list.push_back({ a,i });
        y_list.push_back({ b,i });
        z_list.push_back({ c,i });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}