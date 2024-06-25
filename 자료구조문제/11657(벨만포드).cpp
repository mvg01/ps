#include <bits/stdc++.h>
#define INF 999999999
using namespace std;
// 벨만-포드(O VE) : 다익스트라 알고리즘 (O E log V) 보다 느리지만
// 모든 간선을 검사하기에 음수인 간선에 대해서도 최적의 해를 찾을 수 있다.

int n, m;
vector<pair<pair<int, int>, int>>mat;
long long dis[501];  // 언더플로우 방지

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        mat.push_back({ { a,b }, c });
    }
}

void solve() {
    for (int i = 1; i <= n; i++)
        dis[i] = INF;
    dis[1] = 0;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < m; j++) {
            int start = mat[j].first.first;
            int end = mat[j].first.second;
            int weight = mat[j].second;
            if (dis[start] != INF) {
                if (dis[end] > dis[start] + weight)
                    dis[end] = dis[start] + weight;
            }
        }
    }
    // 음수 순환이 있는지 체크
    for (int i = 0; i < m; i++) {
        int start = mat[i].first.first;
        int end = mat[i].first.second;
        int weight = mat[i].second;
        if (dis[start] != INF) {
            if (dis[end] > dis[start] + weight) {
                cout << -1;
                return;
            }
        }
    }
    for (int i = 2; i <= n; i++) {
        if (dis[i] == INF)
            cout << -1 << '\n';
        else
            cout << dis[i] << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}