#include <iostream>
#include <queue>
#include <vector>
using namespace std;

vector<int>v[100001];
vector<int>v2[100001];
int visited[100001];   // 각 라인에 대한 환승 여부 (라인 당 한번씩 b가 있는지 확인)
int visited2[100001];  // 역 번호 방문 여부 (중복 열차 확인 필요 X)
int n, l, a, b, ans = -1;

void input() {
    int x;
    cin >> n >> l;
    for (int i = 1; i <= l; i++) {
        while (1) {
            cin >> x;
            if (x == -1)
                break;
            v[i].push_back(x);  // i번 노선의 역 번호가 담긴 리스트
            v2[x].push_back(i); // x번 역에서 갈아탈 수 있는 노선이 담긴 리스트
        }
    }
    cin >> a >> b;
}

void solve() {
    queue<pair<int, int>>q;
    for (int i = 0; i < v2[a].size(); i++) { // 시작 지점을 포함한 노선을 큐에 담는다. 
        visited[v2[a][i]] = 1;
        q.push({ v2[a][i], 0 });
    }
    visited2[a] = 1;  // a번 역 방문

    while (!q.empty()) {
        int line = q.front().first;  // 노선 정보
        int t = q.front().second;  // 환승 횟수
        q.pop();
        for (int i = 0; i < v[line].size(); i++) {  //line 노선의 역을 탐색
            int num = v[line][i];
            if (num == b) {  // 목표 역이면 return
                ans = t;
                return;
            }
            if (visited2[num]) // 방문한 적이 있는 번호의 역 건너뛰기
                continue;
            visited2[num] = 1;
            if (v2[num].size() > 1) {  // 환승할 수 있는 노선이 있다면
                for (int j = 0; j < v2[num].size(); j++) {
                    if (visited[v2[num][j]]) // 이미 확인한 노선이라면 건너뛰기
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