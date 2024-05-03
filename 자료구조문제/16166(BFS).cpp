#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

int n, e, k, a, res = 11;
vector<int>v[10];  // 각 호선의 역 번호 정보
map<int, vector<int>>m;  // 각각의 역 번호가 가진 호선 리스트
bool visited[10];

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> k;
        for (int j = 0; j < k; j++) {
            cin >> a;
            if (m.find(a) == m.end()) 
                m[a] = vector<int>();
            m[a].push_back(i);
            v[i].push_back(a);
        }
    }
    cin >> e;
}

int bfs(int line) {
    queue<pair<int, int>>q;
    q.push({ line, 0 });
    visited[line] = 1;
    while (!q.empty()) {
        int l = q.front().first;
        int cnt = q.front().second;
        q.pop();
        for (int i = 0; i < v[l].size(); i++) {
            int next = v[l][i];
            if (next == e)
                return cnt;
            for (int j = 0; j < m[next].size(); j++) {
                int z = m[next][j];
                if (!visited[z]) {
                    q.push({ z,cnt + 1 });
                    visited[z] = 1;
                }
            }
        }
    }
    return 11;
}

void solve() {
    for (int i = 0; i < m[0].size(); i++) {
        res = min(res, bfs(m[0][i]));
        for (int j = 0; j < 10; j++)
            visited[j] = 0;
    }
    if (res != 11)
        cout << res;
    else
        cout << -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}