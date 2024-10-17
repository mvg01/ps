#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, sum = 0;
int parent[200001];
vector<pair<int, pair<int, int>>>v;

void init() {
    for (int i = 0; i <= 200000; i++)
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
    return a.first < b.first;
}

int kruskal() {
    int dis = 0;  // 최단 경로
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!sameparent(v[i].second.first, v[i].second.second)) {
            dis += v[i].first;
            setunion(v[i].second.first, v[i].second.second);
            cnt++;
        }
        if (cnt == m - 1)
            break;
    }
    return dis;
}

void solve() {
    sort(v.begin(), v.end(), compare); // 가중치 오름차순 정렬
    init();  
    int min_dis = kruskal();  // 최단 경로 가중치
    cout << sum - min_dis << '\n';   // 전체 경로 가중치 - 최단 경로 가중치
}

void input() {
    while (1) {
        cin >> m >> n;
        if (m == 0 && n == 0)
            break;
        int x, y, z;
        for (int i = 0; i < n; i++) {
            cin >> x >> y >> z;
            sum += z;   // 전체 경로 가중치 합
            v.push_back({ z,{x,y} });
        }
        solve();
        v.clear();
        sum = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}