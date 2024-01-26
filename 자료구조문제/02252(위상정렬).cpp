#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> 
using namespace std;

int n, m;
vector<int>v[32001];
vector<int>res;
int in[32001];

void input() {
    int a, b;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b;
        v[a].push_back(b);
        in[b]++;
    }
}

void solve() {
    queue<int>q;
    int r = 1;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push(i);
            res.push_back(i);
        }
    }
    while (!q.empty()) {
        int s = q.front();
        q.pop();
        for (int i = 0; i < v[s].size(); i++) {
            int x = v[s][i];
            in[x]--;
            if (in[x] == 0) {
                q.push(x);
                res.push_back(x);
            }
        }
    }
    for (int i = 0; i < n; i++)
        cout << res[i] << ' ';
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}