#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

int t, n, m;
bool chk = 0;
vector<int>v[1001];
int visited[1001];

// 핵심은 따로 떨어져 있는 원의 색은 1로 모두 고정

void solve(int start) {
    queue<int>q;
    q.push(start);
    while (!q.empty()) {
        int x = q.front();
        int color = visited[x];
        q.pop();
        for (int i = 0; i < v[x].size(); i++) {
            if (color == visited[v[x][i]]) {
                chk = 1;  //불가능한 경우
                break;
            }
            if (visited[v[x][i]] == 0) { // 색이 1이면 2로, 2면 1로
                visited[v[x][i]] = (color == 1) ? 2 : 1;
                q.push(v[x][i]);
            }
        }
        if (chk)
            break;
    }
}

void input() {
    cin >> t;
    int a, b;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < m; i++) {
            cin >> a >> b;
            v[a].push_back(b);
            v[b].push_back(a);
        }
        for (int i = 1; i <= n; i++) {
            if (!visited[i]) {
                visited[i] = 1;  //색 1로 시작
                solve(i);
            }
        }
        if (chk)
            cout << "impossible\n";
        else
            cout << "possible\n";
        for (int i = 0; i < 1001; i++) {
            v[i].clear();
            visited[i] = 0;
        }
        chk = 0;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}