#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int t, n, k, w;
int dis[1001], in[1001];
vector<int>v[1001];

int solve() {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>q;
    for (int i = 1; i <= n; i++) {
        if (in[i] == 0) {
            q.push({ dis[i], i });
            if (i == w) 
                return dis[i];
        }
    }
    while (!q.empty()) {
        int plus = q.top().first;
        int p = q.top().second;
        q.pop();
        for (int i = 0; i < v[p].size(); i++) {
            int next = v[p][i];
            in[next]--;
            if (in[next] == 0) {
                q.push({ plus + dis[next],next });
                if (next == w) {
                    return plus + dis[next];
                }
            }
        }
    }
}

void input() {
    cin >> t;
    while (t--) {
        int a, b;
        cin >> n >> k;
        for (int i = 1; i <= n; i++)
            cin >> dis[i];
        for (int i = 0; i < k; i++) {
            cin >> a >> b;
            v[a].push_back(b);
            in[b]++;
        }
        cin >> w;

        cout << solve() << '\n';
        for (int i = 0; i <= n; i++) {
            v[i].clear();
            in[i] = 0;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}