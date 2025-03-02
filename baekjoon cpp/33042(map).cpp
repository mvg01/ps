#include <bits/stdc++.h>
using namespace std;

int n, ans = 0;
map<string, int>m;
void input() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        m[s]++;
        if (ans == 0 && m[s] > 4)
            ans = i + 1;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}