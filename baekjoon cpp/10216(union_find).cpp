#include <iostream>
#include <vector>
#include <tuple>
#include <cmath>
using namespace std;

int t, n;
int parent[3001];
vector<tuple<int, int, int>>v;

void init() {
    for (int i = 1; i <= 3000; i++)
        parent[i] = i;
}

int getparent(int x) {
    if (x == parent[x])
        return x;
    else
        return parent[x] = getparent(parent[x]);
}

bool sameparent(int a, int b) {
    int aa = getparent(a);
    int bb = getparent(b);
    if (aa == bb)
        return 1;
    else
        return 0;
}

void setunion(int a, int b) {
    int aa = getparent(a);
    int bb = getparent(b);
    if (aa > bb)
        parent[aa] = bb;
    else
        parent[bb] = aa;
}

void input() {
    int x, y, r;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> r;
            v.push_back({ x, y, r });
        }
        init();
        int res = n;
        for (int i = 0; i < n - 1; i++) {
            for (int j = i + 1; j < n; j++) {
                if (sameparent(i, j))
                    continue;
                int ax = get<0>(v[i]);
                int ay = get<1>(v[i]);
                int ar = get<2>(v[i]);
                int bx = get<0>(v[j]);
                int by = get<1>(v[j]);
                int br = get<2>(v[j]);
                double dis = sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay));
                if (dis <= ar + br) {
                    setunion(i, j);
                    res--;
                }
            }
        }
        cout << res << '\n';
        v.clear();
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}