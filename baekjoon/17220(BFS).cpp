#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n, m, t;
vector<int>mat[26];
vector<int>mat2[26];
queue<int>q;
int visited[26];

void input() {
    char a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        int x = a - 'A';
        int y = b - 'A';
        mat[x].push_back(y);  //주는
        mat2[y].push_back(x);  //받는
    }
    cin >> t;
    for (int i = 0; i < t; i++) {
        cin >> a;
        q.push(a - 'A');
        visited[a - 'A'] = 9;  // 단속 걸린 곳
    }
}

void solve() {
    // 첫번째 bfs -> 단속 걸린 곳 기준으로 연결된 곳은 마약 공급 X
    while (!q.empty()) {  
        int point = q.front();
        q.pop();
        for (int i = 0; i < mat[point].size(); i++) {
            int next = mat[point][i];
            if (!visited[next]) {
                visited[next] = 1;
                q.push(next);
            }
        }
    }
    // 두번째 bfs -> 마약 원산지에서 단속 걸린 곳을 피하면서 마약을 공급 
    for (int i = 0; i < n; i++) {
        if (mat2[i].size() == 0 && visited[i] == 0) {  // 걸리지 않은 마약 원산지
            q.push(i);
            visited[i] = 1;
        }
    }
    while (!q.empty()) {  // 단속반에 끊겼어도 다른 공급책이 존재하는 경우 or 단속 관계 없이 공급받음
        int point = q.front();
        q.pop();
        for (int i = 0; i < mat[point].size(); i++) {
            int next = mat[point][i];
            if (visited[next] == 0 || visited[next] == 1) {
                visited[next] = 2;
                q.push(next);
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (visited[i] == 2) 
            ans++;   
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}