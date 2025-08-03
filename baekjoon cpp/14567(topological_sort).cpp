#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

int n, m;
vector<int>v[1001];
int res[1001] = { 0 };
int in[1001] = { 0 };

void input() {
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        in[b]++;  //선수과목의 개수
    }
}

void solve() {
    queue<int>q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0)
            q.push(i);
        res[i] = 1;
    }
    while (!q.empty()) {
        int p = q.front();
        q.pop();
        for (int i = 0; i < v[p].size(); i++) {
            in[v[p][i]]--;

            if (in[v[p][i]] == 0)  //선수과목이 없다면 큐에 담는다.
                q.push(v[p][i]);

            res[v[p][i]] = max(res[v[p][i]], res[p] + 1);
        }
    }
    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}