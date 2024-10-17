#include <iostream>
#include <vector>
#include <queue>
#include <tuple>
#include <algorithm>
using namespace std;

int n, m, s, e;
int parent[100001];
int visited[100001];
vector<pair<int, pair<int, int>>>v;
vector<pair<int, int>>mat[100001];

void init() {
    for (int i = 0; i < 100001; i++)
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

bool compare(pair<int, pair<int, int>>a, pair<int, pair<int, int>>b) {
    return a.first > b.first;
}

void kruskal() {
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!sameparent(v[i].second.first, v[i].second.second)) {
            setunion(v[i].second.first, v[i].second.second);
            cnt++;
            mat[v[i].second.first].push_back({ v[i].second.second,v[i].first });
            mat[v[i].second.second].push_back({ v[i].second.first,v[i].first });
        }
        if (cnt == n - 1)
            break;
    }
}

void bfs() {
    queue<pair<int, int>>q;
    for (int i = 0; i < mat[s].size(); i++) {
        q.push({ mat[s][i].first,mat[s][i].second });
        visited[mat[s][i].first] = 1;
    }
    while (!q.empty()) {
        int ver = q.front().first;
        int w = q.front().second;
        q.pop();
        if (ver == e) {
            cout << w;
            return;
        }
        for (int i = 0; i < mat[ver].size(); i++) {
            if(!visited[mat[ver][i].first]) {
                q.push({ mat[ver][i].first, min(mat[ver][i].second, w) });
                visited[mat[ver][i].first] = 1;
            }
        }
    }
    cout << 0;
}

void solve() {
    sort(v.begin(), v.end(), compare); // 가중치 내림차순 정렬
    init();
    kruskal();
    bfs();
}

void input() {
    cin >> n >> m >> s >> e;
    int a, b, c;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        v.push_back({ c,{a,b} });
    }
    solve();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}