#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int r, c, t, ans = 0;
int mat[1001][1001];
vector<int>p;
void input() {
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> mat[i][j];
        }
    }
    cin >> t;
}

void solve() {
    for (int i = 0; i < r - 2; i++) {
        for (int j = 0; j < c - 2; j++) {
            vector<int>v;
            for (int a = 0; a < 3; a++) {
                for (int b = 0; b < 3; b++) {
                    v.push_back(mat[i + a][j + b]);
                }
            }
            sort(v.begin(), v.end());
            p.push_back(v[4]);
        }
    }
    for (int i = 0; i < p.size(); i++) {
        if (p[i] >= t)
            ans++;
    }
    cout << ans;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}