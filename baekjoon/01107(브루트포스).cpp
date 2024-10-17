#include <iostream>
#include <string>
#include <vector>
using namespace std;

int n, m, len, res = 1000000;
bool chk[10];
string f;

void input() {
    int x;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> x;
        chk[x] = 1;
    }
    f = to_string(n);
    len = f.length();
}

void solve() {  
    for (int i = 0; i <= 999999; i++) {
        string temp = to_string(i);
        bool no = 0;
        len = temp.length();
        for (int j = 0; j < len; j++) {
            if (chk[temp[j] - '0'])
                no = 1;
        }
        if (no)
            continue;
        int x = len;
        x += abs(n - i);
        res = min(res, x);
    }

    res = min(res, abs(100 - n));
 
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}