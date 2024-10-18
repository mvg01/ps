#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<pair<int, int>>v(200001);
struct cmp {
    bool operator()(pair<int, int>& a, pair<int, int>& b) {
        if (a.first == b.first)
            return a.second > b.second; // second는 오름차순
        return a.first < b.first; // first는 내림차순
    }
};
priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> pq;

void solve() {
    int res = 0;
    for (int i = 0; i < n * 24; i++) {
        int p = pq.top().first;
        int s = pq.top().second;
        pq.pop();
        int x = s + p;
        if (x <= 100)
            pq.push({ p,x });
        else {
            pq.push({ 100 - s, s });
            i--;
        }
    }
    while (!pq.empty()) {
        res += pq.top().second;
        pq.pop();
    }
    cout << res;
}

void input() {
    cin >> n >> m;
    for (int i = 0; i < m; i++)
        cin >> v[i].second;
    for (int i = 0; i < m; i++)
        cin >> v[i].first;
    for (int i = 0; i < m; i++)
        pq.push(v[i]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}