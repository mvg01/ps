// 1번째 풀이

#include <bits/stdc++.h>
using namespace std;

// 오일러 경로 알고리즘: 경로의 중간에 위치한 모든 정점은 경로에 들어올 때마다 간선을 하나 사용해 들어오고, 나갈 때마다 하나의 간선을 사용한다. 
// 즉, 중간 정점은 항상 "들어옴"과 "나감"이 한 쌍씩 있어야 하므로, 그 정점의 전체 간선 수(차수)는 짝수가 된다.
// 따라서 정점으로부터 경로의 개수가 홀수인 정점이이 2개(시작과 끝 정점) 오일러 경로이다.
// 추가로 홀수인 경로의 개수가 0개 있는(모든 정점의 경로 개수가 짝수라면) 오일러 회로로서 시작 정점과 끝 정점이 같은 경우인데, 오일러 경로를 만족한다고 할 수 있다.

int v, e, cnt = 1;
vector<int>mat[3001];
bool vis[3001];

void dfs(int s) {
    for (auto i : mat[s]) {
        if (!vis[i]) {
            vis[i] = 1;
            cnt++;
            dfs(i);
        }
    }
}

void solve() {
    vis[1] = 1;
    dfs(1);  // 임의의 정점으로부터 모든 정점이 연결되었는지 확인인
    if (cnt != v) {
        cout << "NO";
        return;
    }
    int t = 0;
    for (int i = 1; i <= v; i++) {
        if (mat[i].size() % 2 == 1)  // 간선 개수가 홀수인 정점 수 체크
            t++;
    }
    if (t == 0 || t == 2)
        cout << "YES";
    else
        cout << "NO";
}

void input() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        mat[a].push_back(b);
        mat[b].push_back(a);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}

// 2번째 풀이

#include <bits/stdc++.h>
using namespace std;

// 분리집합: 하나의 부모에서 연결이 가능한지 체크위함
// 탐색: 가장 간선이 많은 정점에서 시작하여 간선을 방문처리

int v, e;
int p[3001];
vector<pair<int, int>>mat[3001];
bool vis[3001];

int get_parent(int x) {
    if (x == p[x])
        return x;
    else
        return p[x] = get_parent(p[x]);
}

void set_union(int a, int b) {
    int a1 = get_parent(a);
    int b1 = get_parent(b);
    if (a1 > b1)
        p[a1] = b1;
    else
        p[b1] = a1;
}

void solve() {
    int s = 0, mx = 0;   // 간선이 가장 많은 정점에서부터 묶기 시작
    for (int i = 1; i <= 3000; i++) {
        p[i] = i;
        if (mat[i].size() > mx) {
            s = i;
            mx = mat[i].size();
        }
    }
    for (int i = 0; i < e; i++) {
        int nxt = -1;
        for (auto j : mat[s]) {
            if (!vis[j.second]) {
                vis[j.second] = 1;
                nxt = j.first;
                break;
            }
        }
        if (nxt == -1) {  // 연결 가능한 간선이 없음
            cout << "NO";
            return;
        }
        set_union(get_parent(nxt), get_parent(s));  
        s = nxt;
    }
    for (int i = 1; i < v; i++) {
        if (get_parent(i) != get_parent(i + 1)) {
            cout << "NO";
            return;
        }
    }
    cout << "YES";
}

void input() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        int a, b;
        cin >> a >> b;
        mat[a].push_back({ b,i });
        mat[b].push_back({ a,i });
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}