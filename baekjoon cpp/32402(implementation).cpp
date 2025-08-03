#include <bits/stdc++.h>
using namespace std;

int n, y = 0, x = 0, yy = -1, xx = 0;
int mr[4][2] = { {1,-1},{1,1},{-1,1},{-1,-1} };
int ml[4][2] = { {1,1},{-1,1},{-1,-1},{1,-1} };
int w[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int a[4][2] = { {0,-1},{1,0},{0,1},{-1,0} };
int s[4][2] = { {-1,0},{0,-1},{1,0},{0,1} }; 
int d[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };
int dir = 0;
string in;

void solve() {
    
}

void input() {
    cin >> n;
    while (n--) {
        cin >> in;
        if (in == "W") {
            y += w[dir][0];
            x += w[dir][1];
            yy += w[dir][0];
            xx += w[dir][1];
        }
        else if (in == "S") {
            y += s[dir][0];
            x += s[dir][1];
            yy += s[dir][0];
            xx += s[dir][1];
        }
        else if (in == "A") {
            y += a[dir][0];
            x += a[dir][1];
            yy += a[dir][0];
            xx += a[dir][1];
        }
        else if (in == "D") {
            y += d[dir][0];
            x += d[dir][1];
            yy += d[dir][0];
            xx += d[dir][1];
        }
        else if (in == "MR") {
            yy += mr[dir][0];
            xx += mr[dir][1];
            dir = (dir + 1) % 4;
        }
        else if (in == "ML") {
            yy += ml[dir][0];
            xx += ml[dir][1];
            dir = (dir + 3) % 4;
        }
        cout << x << ' ' << y << ' ' << xx << ' ' << yy << '\n';
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}