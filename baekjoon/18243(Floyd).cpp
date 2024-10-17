#include <bits/stdc++.h>
#define INF 999999999
using namespace std;

int n, k;
int mat[101][101];
void input() {
    int a, b;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++)
            mat[i][j] = INF;
    }
    for (int i = 0; i < k; i++) {
        cin >> a >> b;
        mat[a - 1][b - 1] = 1;
        mat[b - 1][a - 1] = 1;
    }
}

void solve() {
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) 
                mat[i][j] = min(mat[i][j], mat[i][k] + mat[k][j]); 
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (mat[i][j] > 6) {
                cout << "Big World!";
                return;
            }
        }
    }
    cout << "Small World!";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve();
}