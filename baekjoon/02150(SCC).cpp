#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;

int v, e, a, b, id = 0;
int id_list[10001];  
bool visited[10001];
bool chk[10001];
vector<int>mat[10001];
vector<vector<int>>list;
stack<int>s;

void input() {
    cin >> v >> e;
    for (int i = 0; i < e; i++) {
        cin >> a >> b;
        mat[a].push_back(b);
    }
}

int dfs(int x) {
    id_list[x] = ++id;
    s.push(x);  // 스택에 방문 정점 push
    int parent = id_list[x];
    for (int i = 0; i < mat[x].size(); i++) {
        int ver = mat[x][i];
        if (id_list[ver] == 0)  // 아직 방문하지 않은 정점
            parent = min(parent, dfs(ver));
        else if (!visited[ver])  // 방문했지만 완료되지 않은 정점
            parent = min(parent, id_list[ver]);
    }
    if (parent == id_list[x]) {
        vector<int>scc;
        while (1) {
            int vertex = s.top();
            s.pop();
            visited[vertex] = 1;
            scc.push_back(vertex);
            if (vertex == x) 
                break;
        }
        sort(scc.begin(), scc.end());
        list.push_back(scc);
    }
    return parent;
}

void solve() {
    for (int i = 1; i <= v; i++) {
        if (!visited[i])
            dfs(i);
    }
    cout << list.size() << '\n';
    for (int i = 1; i <= v; i++) {
        if (!chk[i]) {
            for (int j = 0; j < list.size(); j++) {  // 작은 정점 번호부터 나열
                if (list[j][0] == i) {
                    for (int k = 0; k < list[j].size(); k++) {
                        cout << list[j][k] << ' ';
                        chk[list[j][k]] = 1;
                    }
                }
            }
            cout << -1 << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}