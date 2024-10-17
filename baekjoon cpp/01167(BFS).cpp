#include <bits/stdc++.h>
using namespace std;

int v;
int dis[100001];
vector<pair<int, int>>mat[100001];

void dfs(int e, int s) {
    for (int i = 0; i < mat[e].size(); i++) {
        if (dis[mat[e][i].first] == -1) {
            dis[mat[e][i].first] = s + mat[e][i].second;
            dfs(mat[e][i].first, s + mat[e][i].second);
        }
    }
}

void input() {
    cin >> v;
    for (int i = 0; i < v; i++) {
        int x, a, b;
        cin >> x;
        while (1) {
            cin >> a;
            if (a == -1)
                break;
            cin >> b;
            mat[x].push_back({ a,b });
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    memset(dis, -1, sizeof(dis));
    dis[1] = 0;
    dfs(1, 0);  // 임의의 정점에서 가장 먼 정점
    int md = 0, mv = 0;
    for (int i = 1; i <= v; i++) {
        if (md < dis[i]) {
            md = dis[i];
            mv = i;
        }
    }
    memset(dis, -1, sizeof(dis));
    dis[mv] = 0;
    dfs(mv, 0);  // 가장 먼 정점에서 가장 멀리 떨어진 정점이 트리의 지름
    md = 0;
    for (int i = 1; i <= v; i++) 
        md = max(md, dis[i]);
    cout << md << "\n";
}