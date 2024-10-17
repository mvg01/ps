#include <bits/stdc++.h>
using namespace std;

int n;
unordered_map<string, int>m;
int parent[200001], cnt[200001];

void init() {
    m.clear();
    for (int i = 0; i < 200001; i++) {
        parent[i] = i;
        cnt[i] = 1;
    }
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
    if (a != b) {
        parent[b] = a;
        cnt[a] += cnt[b];
    }
}

void input() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        int idx = 1;
        init();
        for (int i = 0; i < n; i++) {
            string a, b;
            int a1, b1;
            cin >> a >> b;
            if (m.find(a) == m.end()) {
                a1 = idx;
                m.insert({ a, idx++ });
            }
            else
                a1 = m[a];
            if (m.find(b) == m.end()) {
                b1 = idx; 
                m.insert({ b, idx++ });
            }
            else
                b1 = m[b];
            set_union(a1, b1);
            cout << cnt[parent[a1]] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}