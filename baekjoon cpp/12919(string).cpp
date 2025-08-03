#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

void solve(string s, string t) {
    if (s == t) {
        cout << 1;
        exit(0);
    }
    else if (s.length() >= t.length())
        return;
    else {
        if (t.back() == 'A') {
            string temp = t;
            temp.pop_back();
            solve(s, temp);
        }
        if (t.front() == 'B') {
            string temp = t;
            reverse(temp.begin(), temp.end());
            temp.pop_back();
            solve(s, temp);
        }
    }
}

void input() {
    string s, t;
    cin >> s >> t;
    solve(s, t);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    cout << 0;
}