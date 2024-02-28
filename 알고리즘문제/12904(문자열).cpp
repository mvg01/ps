#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

string s, t;
void input() {
    cin >> s >> t;
}

void solve() {
    int slen = s.size();
    int tlen = t.size();
    for (int i = tlen - 1; i >= slen; i--) {
        if (t[i] == 'A')
            t.pop_back();
        else {
            t.pop_back();
            reverse(t.begin(), t.end());
        }
    }
    if (t == s)
        cout << 1;
    else
        cout << 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}