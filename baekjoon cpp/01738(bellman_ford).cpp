#include <bits/stdc++.h>
#define INF 1e9
using namespace std;

int n, m, u, v, w;
int dis[101], chk[101], ans[101];
vector<pair<pair<int, int>, int>>mat;

void solve() {
    for (int i = 0; i < 101; i++) dis[i] = INF;
    dis[1] = 0;
    for (int i = 0; i < n - 1; i++) { // 벨만포드
        for (int j = 0; j < m; j++) {
            int start = mat[j].first.first;
            int end = mat[j].first.second;
            int weight = mat[j].second;
            if (dis[start] != INF) {
                if (dis[end] > dis[start] + weight) {
                    dis[end] = dis[start] + weight;
                    ans[end] = start;
                }
            }
        }
    }
    // 양수 사이클 체크
    for (int j = 0; j < m; j++) {
        int start = mat[j].first.first;
        int end = mat[j].first.second;
        int weight = mat[j].second;
        if (dis[start] != INF && dis[end] > dis[start] + weight) {
            chk[start] = 1;
            chk[end] = 1;
        }
    }
    // 양수 사이클로 인해 영향받을 수 있는 정점들도 사이클 처리
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int start = mat[j].first.first;
            int end = mat[j].first.second;
            if (chk[start])
                chk[end] = 1;
        }
    }
    if (dis[n] == INF)  // 목적지 도달 불가
        cout << -1;
    else if (chk[n])  // 목적지 가던 중 양수 사이클 발생
        cout << -1;
    else {
        stack<int>s;
        int temp = n;
        s.push(n);
        while (temp != 1) {  // 경로 역추적
            temp = ans[temp];
            s.push(temp);
        }
        while (s.size()) {
            cout << s.top() << ' ';
            s.pop();
        }
    }
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> u >> v >> w;
        mat.push_back({ { u,v }, -w });  // 음수와 양수 전환
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}