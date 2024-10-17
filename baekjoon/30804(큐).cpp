#include <bits/stdc++.h>
using namespace std;

int n, a[200001], k[200001];
queue<int>q;

void input() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
}

void solve() {
    int idx = 0, cnt = 0, res = 0;
    while (cnt != 2) {
        if (!k[a[idx]]) 
            cnt++;
        k[a[idx]]++;
        q.push(a[idx]);
        idx++;
        if (idx == n)
            break;
    }
    res = q.size();
    for (int i = idx; i < n; i++) {
        if (k[a[i]]) {
            k[a[i]]++;
            q.push(a[i]);
            res = max(res, (int)q.size());
        }
        else {
            if (cnt == 2) {
                while (1) {
                    int x = q.front();
                    k[x]--;
                    q.pop();
                    if (k[x] == 0)
                        break;
                }
                cnt--;
            }
            k[a[i]]++;
            q.push(a[i]);
            res = max(res, (int)q.size());
            cnt++;
        }
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}