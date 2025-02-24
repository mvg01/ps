#include <bits/stdc++.h>
using namespace std;

int n, m, c, qr;
unordered_map<string, vector<string>>mp;
unordered_map<string, int>chk;

void solve(string s) {
    int a = 0;
    set<string>vis;
    queue<string>q;
    q.push(s);
    while (q.size()) {
        string s = q.front();
        q.pop();
        for (string j : mp[s]) {
            if (chk[j] == 1)
                q.push(j);
            else {
                a++;
                vis.insert(j);
            }
        }
    }
    cout << vis.size() << ' ' << a << '\n';
}

void input() {
    cin >> n >> m;
    chk["main"] = 1;  // 디렉터리 여부
    for (int i = 0; i < n + m; i++) {
        string p, f;
        cin >> p >> f >> c;
        chk[p] = 1;  // p는 디렉터리
        if (mp.find(p) == mp.end()) {
            vector<string>child;
            child.push_back(f);
            mp[p] = child;
        }
        else
            mp[p].push_back(f);
        chk[f] = c;
    }
    cin >> qr;
    for (int i = 0; i < qr; i++) {
        string query, res;
        cin >> query;
        int l = query.length();
        for (int i = 0; i < l; i++) {
            res += query[i];
            if (query[i] == '/')
                res = "";
        }
        solve(res);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}