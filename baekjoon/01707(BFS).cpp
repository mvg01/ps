#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int t, v, e;
bool chk = 0;
int visited[20001] = { 0 };
vector<int>mat[20001];

// 이분 그래프 상황을 1과 2로 분리한다. 1과 1이 연결되면 이분그래프 X
void solve() { 
    queue<pair<int, int>>q;
    for (int i = 1; i <= v; i++) {  //모든 정점에 대해서 탐색
        if (visited[i] == 0) {  //아직 방문하지 않은 정점
            visited[i] = 1;   //시작정점의 분류는 1로
            for (int j = 0; j < mat[i].size(); j++) {
                if (!visited[mat[i][j]]) {
                    q.push({ mat[i][j], 2 });  //시작정점과 연결된 정점은 2로
                    visited[mat[i][j]] = 2;
                }
            }
            while (!q.empty()) {
                int ver = q.front().first;
                int mode = q.front().second;
                q.pop();
                for (int i = 0; i < mat[ver].size(); i++) {
                    if (mode == 1) {
                        if (visited[mat[ver][i]] == 1) {
                            chk = 1;
                            return;
                        }
                    }
                    else {
                        if (visited[mat[ver][i]] == 2) {
                            chk = 1;
                            return;
                        }
                    }
                    if (visited[mat[ver][i]] == 0) {
                        if (mode == 1) {
                            q.push({ mat[ver][i], 2 });
                            visited[mat[ver][i]] = 2;
                        }
                        else {
                            q.push({ mat[ver][i], 1 });
                            visited[mat[ver][i]] = 1;
                        }
                    }
                }
            }
        }
    }
}

void input() {
    cin >> t;
    while (t--) {
        int a, b;
        chk = 0;
        cin >> v >> e;
        for (int i = 0; i < e; i++) {
            cin >> a >> b;
            mat[a].push_back(b);
            mat[b].push_back(a);
        }
        solve();
        if (chk)
            cout << "NO\n";
        else
            cout << "YES\n";
        for (int i = 0; i <= v; i++) {
            mat[i].clear();
            visited[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}