#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, a[101];
vector<int>v[101];
vector<int>res;
int visited[101];

void input() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        v[a[i]].push_back(i);
    }
}

void dfs(int num, int start) {  // 사이클이 형성되면 뽑는 방법 리스트에 추가
    if (num == start) {
        res.push_back(start);
        return;
    }
    for (int i = 0; i < v[num].size(); i++) {
        int next = v[num][i];
        if (!visited[next]) {
            visited[next] = 1;
            dfs(next, start);
        }
    }
}

void solve() {
    for (int i = 1; i <= n; i++) {
        visited[i] = 1;
        dfs(i, a[i]);
        for (int j = 1; j <= n; j++)
            visited[j] = 0;
    }
    cout << res.size() << '\n';
    sort(res.begin(), res.end());
    for (int i = 0; i < res.size(); i++)
        cout << res[i] << '\n';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}