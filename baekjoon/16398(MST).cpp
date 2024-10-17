#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int parent[1001];
int mat[1001][1001];
vector<pair<int, pair<int, int>>>v;

void init() {
    for (int i = 0; i < 1001; i++)
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

void kruskal() {
    long long dis = 0;  // 최단 경로
    int cnt = 0;
    for (int i = 0; i < v.size(); i++) {
        if (!sameparent(v[i].second.first, v[i].second.second)) {
            dis += v[i].first;
            setunion(v[i].second.first, v[i].second.second);
            cnt++;
        }
        if (cnt == n - 1)
            break;
    }
    cout << dis;
}

void solve() {
    sort(v.begin(), v.end(), compare); // 가중치 오름차순 정렬
    init();  
    kruskal();
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j && mat[i][j] != 0) 
                v.push_back({ mat[i][j],{i,j} });
        }
    }
    solve();
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}