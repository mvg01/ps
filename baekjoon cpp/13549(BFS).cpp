#include <bits/stdc++.h>
#define INF 9999999
using namespace std;

// 0-1 BFS 활용

int n, k;
int visited[100001];
void input() {
    cin >> n >> k;
}

void solve() {
    deque<pair<int, int>>dq;
    dq.push_back({ n,0 });
    for (int i = 0; i <= 100000; i++)
        visited[i] = INF;
    visited[n] = 1;
    while (!dq.empty()) {
        int e = dq.front().first;
        int v = dq.front().second;
        dq.pop_front();
        if (e == k) {
            cout << v;
            return;
        }
        if (e * 2 <= 100000) {
            if (visited[e * 2] > v) {
                visited[e * 2] = v;
                dq.push_front({ e * 2 ,v });
            }
        }
        if (e + 1 <= 100000 && visited[e + 1] > v + 1) {
            visited[e + 1] = v + 1;
            dq.push_back({ e + 1,v + 1 });
        }
        if (e - 1 >= 0 && visited[e - 1] > v + 1) {
            visited[e - 1] = v + 1;
            dq.push_back({ e - 1,v + 1 });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}