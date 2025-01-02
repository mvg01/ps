#include <bits/stdc++.h>
using namespace std;

int n;
vector<tuple<int, int, double>>mat;
vector<pair<int, int>>v;
int parent[101];

bool c(tuple<int, int, double>a, tuple<int, int, double>b) {
    return get<2>(a) < get<2>(b);
}

void init() {
    for (int i = 0; i < 101; i++) parent[i] = i;
}

int getParent(int x) {
    if (parent[x] == x)
        return x;
    else
        return parent[x] = getParent(parent[x]);
}

void setUnion(int a, int b) {
    int aa = getParent(a);
    int bb = getParent(b);
    if (aa > bb) 
        parent[aa] = bb;
    else
        parent[bb] = aa;
}

void solve() {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            double dis = sqrt(pow(v[i].first - v[j].first, 2) + pow(v[i].second - v[j].second, 2));
            mat.push_back({ i, j, dis });
        }
    }
    sort(mat.begin(), mat.end(), c);
    init();
    double dis = 0;
    int cnt = 0;
    for (int i = 0; i < mat.size(); i++) {
        auto [x, y, w] = mat[i];
        if (getParent(x) != getParent(y)) {
            setUnion(x, y);
            dis += w;
            cnt++;
        }
        if (cnt == n - 1)
            break;
    }
    printf("%0.2lf", dis / 100);
}

void input() {
    double a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        int x = (int)(a * 100);
        int y = (int)(b * 100);
        v.push_back({ x,y });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}