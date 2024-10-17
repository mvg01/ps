#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int>v[1001];
vector<int>v2[100001];
int visited[1001];
int visited2[100001];
int n, k, m, ans = -1;

void input() {
    int x;
    cin >> n >> k >> m;
    for (int i = 1; i <= m; i++) {
        for (int j = 0; j < k; j++) {
            cin >> x;
            v[i].push_back(x);  // i번 하이퍼 큐브의 역 리스트
            v2[x].push_back(i); // x번 역에서 사용가능한 하이퍼 큐브 리스트
        }
    }
}

void solve() {
    queue<pair<int, int>>q;
    for (int i = 0; i < v2[1].size(); i++) {
        visited[v2[1][i]] = 1;
        q.push({ v2[1][i], 1 });
    }
    visited2[1] = 1;
    while (!q.empty()) {
        int line = q.front().first;  // 노선 정보
        int t = q.front().second;
        q.pop();
        for (int i = 0; i < v[line].size(); i++) {
            int num = v[line][i];
            if (num == n) {
                if (n == 1)  // n이 1이 아니면 추가로 이동을 해줘야 함
                    ans = 1;
                else
                    ans = t + 1;
                return;
            }
            if (visited2[num])
                continue;
            visited2[num] = 1;
            if (v2[num].size() > 1) { 
                for (int j = 0; j < v2[num].size(); j++) {
                    if (visited[v2[num][j]])
                        continue;
                    q.push({ v2[num][j],t + 1 });
                    visited[v2[num][j]] = 1;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
    cout << ans;
}