#include <bits/stdc++.h>
using namespace std;

int n, a, b;
string res;
vector<int>v[500001];
vector<string>s;

void solve(int start) {
    cout << s[start];
    for (int i = 0; i < v[start].size(); i++) 
        solve(v[start][i]);
    return;
}

void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string x;
        cin >> x;
        s.push_back(x);
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> a >> b;
        a--;
        b--;
        v[a].push_back(b);
    }
    // 시작 학교는 a
    solve(a);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}