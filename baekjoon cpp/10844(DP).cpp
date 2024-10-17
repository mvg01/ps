#include <iostream>
#include <vector>
using namespace std;

long long dp[101][10];
vector<vector<int>>v = { {1},{0,2},{1,3},{2,4},{3,5},{4,6},{5,7},{6,8},{7,9},{8} };
void solve() {
    for (int i = 1; i <= 9; i++)
        dp[1][i] = 1;
    for (int i = 2; i <= 100; i++) {
        for (int j = 0; j <= 9; j++) {
            for (int k = 0; k < v[j].size(); k++) {
                dp[i][j] += dp[i - 1][v[j][k]];
                dp[i][j] %= 1000000000;
            }
        }
    }
}

void input() {
    solve();
    int n, res = 0;
    cin >> n;
    for (int i = 0; i <= 9; i++) {
        res += dp[n][i];
        res %= 1000000000;
    }
    cout << res;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    input();
}