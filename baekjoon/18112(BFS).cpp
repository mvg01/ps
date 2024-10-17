#include <bits/stdc++.h>
using namespace std;

string l, k;
int visited[2500];

void input() {
    cin >> l >> k;
}

int toint(string s) {  // 이진수 문자열을 정수로
    int v = 0, base = 1;
    for (int i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '1')
            v += base;
        base *= 2;
    }
    return v;
}

string tostring(int n) {   // 정수를 이진수 문자열로
    if (n == 0)
        return "0";
    string s = "", r = "";
    while (n > 0) {
        s += (n % 2 == 0 ? "0" : "1");
        n /= 2;
    }
    for (int i = s.length() - 1; i >= 0; i--)
        r += s[i];
    return r;
}

void solve() {
    queue<int>q;
    int x = toint(l);
    int y = toint(k);
    visited[x] = 1;
    q.push(x);
    while (!q.empty()) {
        x = q.front();
        int d = visited[x];
        q.pop();
        if (x == y) {
            cout << d - 1;
            return;
        }
        string s = tostring(x);
        for (int i = 1; i < s.length(); i++) {
            string temp = s;
            if (s[i] == '1')
                temp[i] = '0';
            else
                temp[i] = '1';
            int p = toint(temp);
            if (p < 1024) {
                //cout << p << ' ';
                if (!visited[p]) {
                    q.push(p);
                    visited[p] = d + 1;
                }
            }
        }
        if (!visited[x + 1]) {
            q.push(x + 1);
            visited[x + 1] = d + 1;
        }
        if (x - 1 >= 0) {
            if (!visited[x - 1]) {
                q.push(x - 1);
                visited[x - 1] = d + 1;
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}