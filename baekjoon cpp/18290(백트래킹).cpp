#include <iostream>
using namespace std;

int n, m, k, res = -1000000;
int mat[11][11];
bool visited[11][11];

void solve(int cnt,int sum) {
    if (cnt == k) {
        res = max(res, sum);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (visited[i][j])
                continue;
            bool chk = 0;
            if (i != 0) {
                if (visited[i - 1][j])
                    chk = 1;
            }
            if (i != n - 1) {
                if (visited[i + 1][j])
                    chk = 1;
            }
            if (j != 0) {
                if (visited[i][j - 1])
                    chk = 1;
            }
            if (j != m - 1) {
                if (visited[i][j + 1])
                    chk = 1;
            }
            if (!chk) {
                visited[i][j] = 1;
                solve(cnt + 1, sum + mat[i][j]);
                visited[i][j] = 0;
            }
        }
    }
}

void input() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cin >> mat[i][j];
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
    solve(0, 0);
    cout << res;
}